//
// Created by Kishi Kishore N on 23/11/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INCIDENTS 100
#define MAX_ACTIONS   200
#define DESC_LEN      100

/* Status codes for incidents */
#define STATUS_PENDING   0
#define STATUS_ASSIGNED  1
#define STATUS_RESOLVED  2

/* Status codes for units */
#define UNIT_AVAILABLE   0
#define UNIT_BUSY        1

/* Incident types */
#define TYPE_MEDICAL  1
#define TYPE_FIRE     2
#define TYPE_CRIME    3
#define TYPE_UTILITY  4

/* Unit types */
#define UNIT_AMBULANCE    1
#define UNIT_FIRETRUCK    2
#define UNIT_PATROLCAR    3
#define UNIT_UTILITYTEAM  4

/* ---------- DATA STRUCTURES ---------- */

typedef struct {
    int incident_id;
    int type;           /* Medical / Fire / Crime / Utility (use TYPE_*) */
    int severity;       /* 1–10 (higher = more severe) */
    int location_code;
    int status;         /* STATUS_* */
    int arrival_order;  /* smaller = earlier */
} Incident;

typedef struct {
    Incident arr[MAX_INCIDENTS];
    int size;           /* number of incidents stored so far */
    int current_time;   /* used to assign arrival_order */
} PriorityQueue;

/* Linked list for units */
typedef struct UnitNode {
    int unit_id;
    int unit_type;      /* UNIT_* */
    int status;         /* UNIT_AVAILABLE / UNIT_BUSY */
    struct UnitNode *next;
} UnitNode;

/* Stack for actions */
typedef struct {
    char description[DESC_LEN];
} Action;

typedef struct {
    Action arr[MAX_ACTIONS];
    int top;    /* -1 when empty */
} ActionStack;

/* ---------- HELPER FUNCTIONS (STRING NAMES) ---------- */

const char* incidentTypeToString(int type) {
    switch (type) {
        case TYPE_MEDICAL: return "Medical";
        case TYPE_FIRE:    return "Fire";
        case TYPE_CRIME:   return "Crime";
        case TYPE_UTILITY: return "Utility";
        default:           return "Unknown";
    }
}

const char* incidentStatusToString(int status) {
    switch (status) {
        case STATUS_PENDING:  return "PENDING";
        case STATUS_ASSIGNED: return "ASSIGNED";
        case STATUS_RESOLVED: return "RESOLVED";
        default:              return "UNKNOWN";
    }
}

const char* unitTypeToString(int type) {
    switch (type) {
        case UNIT_AMBULANCE:   return "Ambulance";
        case UNIT_FIRETRUCK:   return "FireTruck";
        case UNIT_PATROLCAR:   return "PatrolCar";
        case UNIT_UTILITYTEAM: return "UtilityTeam";
        default:               return "Unknown";
    }
}

const char* unitStatusToString(int status) {
    switch (status) {
        case UNIT_AVAILABLE: return "AVAILABLE";
        case UNIT_BUSY:      return "BUSY";
        default:             return "UNKNOWN";
    }
}

/* Tertiary priority for incident types: Medical > Fire > Crime > Utility */
int getTypePriority(int type) {
    switch (type) {
        case TYPE_MEDICAL: return 4;
        case TYPE_FIRE:    return 3;
        case TYPE_CRIME:   return 2;
        case TYPE_UTILITY: return 1;
        default:           return 0;
    }
}

/* Map incident type to required unit type */
int requiredUnitForIncidentType(int incidentType) {
    switch (incidentType) {
        case TYPE_MEDICAL: return UNIT_AMBULANCE;
        case TYPE_FIRE:    return UNIT_FIRETRUCK;
        case TYPE_CRIME:   return UNIT_PATROLCAR;
        case TYPE_UTILITY: return UNIT_UTILITYTEAM;
        default:           return -1;
    }
}

/* ---------- STACK FUNCTIONS ---------- */

void initStack(ActionStack *stack) {
    stack->top = -1;
}

int isStackEmpty(ActionStack *stack) {
    return stack->top == -1;
}

int isStackFull(ActionStack *stack) {
    return stack->top == MAX_ACTIONS - 1;
}

void pushAction(ActionStack *stack, const char *desc) {
    if (isStackFull(stack)) {
        printf("Action stack is FULL! Cannot log more actions.\n");
        return;
    }
    stack->top++;
    strncpy(stack->arr[stack->top].description, desc, DESC_LEN - 1);
    stack->arr[stack->top].description[DESC_LEN - 1] = '\0';
}

int popAction(ActionStack *stack, Action *out) {
    if (isStackEmpty(stack)) {
        printf("Action stack is EMPTY!\n");
        return 0;
    }
    *out = stack->arr[stack->top];
    stack->top--;
    return 1;
}

void displayStack(ActionStack *stack) {
    if (isStackEmpty(stack)) {
        printf("Action stack is EMPTY.\n");
        return;
    }
    printf("---- ACTION HISTORY (TOP TO BOTTOM) ----\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d: %s\n", i, stack->arr[i].description);
    }
}

/* ---------- LINKED LIST (UNITS) FUNCTIONS ---------- */

UnitNode* createUnitNode(int unit_id, int unit_type, int status) {
    UnitNode *node = (UnitNode*)malloc(sizeof(UnitNode));
    if (!node) {
        printf("Memory allocation failed for unit.\n");
        exit(1);
    }
    node->unit_id = unit_id;
    node->unit_type = unit_type;
    node->status = status;
    node->next = NULL;
    return node;
}

void insertUnit(UnitNode **head, int unit_id, int unit_type) {
    UnitNode *newNode = createUnitNode(unit_id, unit_type, UNIT_AVAILABLE);
    if (*head == NULL) {
        *head = newNode;
    } else {
        UnitNode *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    printf("Unit %d (%s) inserted as AVAILABLE.\n", unit_id, unitTypeToString(unit_type));
}

UnitNode* searchUnitById(UnitNode *head, int unit_id) {
    while (head != NULL) {
        if (head->unit_id == unit_id) return head;
        head = head->next;
    }
    return NULL;
}

UnitNode* searchFirstAvailableUnitByType(UnitNode *head, int unit_type) {
    while (head != NULL) {
        if (head->unit_type == unit_type && head->status == UNIT_AVAILABLE) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void displayUnits(UnitNode *head) {
    if (head == NULL) {
        printf("No emergency units available in the system.\n");
        return;
    }
    printf("-------- EMERGENCY UNITS (Linked List) --------\n");
    printf("%-10s %-15s %-10s\n", "UnitID", "UnitType", "Status");
    while (head != NULL) {
        printf("%-10d %-15s %-10s\n",
               head->unit_id,
               unitTypeToString(head->unit_type),
               unitStatusToString(head->status));
        head = head->next;
    }
}

/* ---------- PRIORITY QUEUE (INCIDENTS) FUNCTIONS ---------- */

void initPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
    pq->current_time = 0;
}

/* Returns 1 if a has strictly higher priority than b */
int isHigherPriority(Incident *a, Incident *b) {
    /* Primary: severity (higher is better) */
    if (a->severity > b->severity) return 1;
    if (a->severity < b->severity) return 0;

    /* Secondary: earliest arrival time (smaller arrival_order is earlier) */
    if (a->arrival_order < b->arrival_order) return 1;
    if (a->arrival_order > b->arrival_order) return 0;

    /* Tertiary: type priority (Medical > Fire > Crime > Utility) */
    int pa = getTypePriority(a->type);
    int pb = getTypePriority(b->type);
    return pa > pb;
}

void insertIncident(PriorityQueue *pq, int incident_id, int type,
                    int severity, int location_code) {
    if (pq->size == MAX_INCIDENTS) {
        printf("Priority queue is FULL! Cannot add more incidents.\n");
        return;
    }
    Incident inc;
    inc.incident_id = incident_id;
    inc.type = type;
    inc.severity = severity;
    inc.location_code = location_code;
    inc.status = STATUS_PENDING;
    pq->current_time++;
    inc.arrival_order = pq->current_time;

    pq->arr[pq->size] = inc;
    pq->size++;
}

/* Return pointer to highest-priority PENDING incident; NULL if none */
Incident* getHighestPriorityPending(PriorityQueue *pq) {
    int bestIndex = -1;
    for (int i = 0; i < pq->size; i++) {
        if (pq->arr[i].status != STATUS_PENDING) continue;
        if (bestIndex == -1 ||
            isHigherPriority(&pq->arr[i], &pq->arr[bestIndex])) {
            bestIndex = i;
        }
    }
    if (bestIndex == -1) return NULL;
    return &pq->arr[bestIndex];
}

/* Find incident by id (any status) */
Incident* findIncidentById(PriorityQueue *pq, int incident_id) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->arr[i].incident_id == incident_id) {
            return &pq->arr[i];
        }
    }
    return NULL;
}

/* Display all PENDING incidents sorted by priority */
void displayPriorityQueue(PriorityQueue *pq) {
    int pendingCount = 0;
    for (int i = 0; i < pq->size; i++) {
        if (pq->arr[i].status == STATUS_PENDING)
            pendingCount++;
    }

    if (pendingCount == 0) {
        printf("No PENDING incidents in the priority queue.\n");
        return;
    }

    Incident *temp = (Incident*)malloc(sizeof(Incident) * pendingCount);
    if (!temp) {
        printf("Memory allocation failed for PQ display.\n");
        return;
    }

    int idx = 0;
    for (int i = 0; i < pq->size; i++) {
        if (pq->arr[i].status == STATUS_PENDING) {
            temp[idx++] = pq->arr[i];
        }
    }

    /* Simple bubble sort by priority (highest first) */
    for (int i = 0; i < pendingCount - 1; i++) {
        for (int j = 0; j < pendingCount - i - 1; j++) {
            if (!isHigherPriority(&temp[j], &temp[j + 1])) {
                Incident tmp = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tmp;
            }
        }
    }

    printf("-------- PRIORITY QUEUE (PENDING incidents sorted) --------\n");
    printf("%-10s %-10s %-10s %-15s %-10s\n",
           "IncID", "Severity", "ArrTime", "Type", "LocCode");
    for (int i = 0; i < pendingCount; i++) {
        printf("%-10d %-10d %-10d %-15s %-10d\n",
               temp[i].incident_id,
               temp[i].severity,
               temp[i].arrival_order,
               incidentTypeToString(temp[i].type),
               temp[i].location_code);
    }

    free(temp);
}

/* Display ALL incidents (any status) – optional helper */
void displayAllIncidents(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("No incidents recorded.\n");
        return;
    }
    printf("-------- ALL INCIDENTS (Any Status) --------\n");
    printf("%-10s %-10s %-10s %-15s %-10s %-10s\n",
           "IncID", "Severity", "ArrTime", "Type", "LocCode", "Status");
    for (int i = 0; i < pq->size; i++) {
        printf("%-10d %-10d %-10d %-15s %-10d %-10s\n",
               pq->arr[i].incident_id,
               pq->arr[i].severity,
               pq->arr[i].arrival_order,
               incidentTypeToString(pq->arr[i].type),
               pq->arr[i].location_code,
               incidentStatusToString(pq->arr[i].status));
    }
}

/* ---------- WORKFLOW OPERATIONS ---------- */

/* A. Report New Incident */
void reportNewIncident(PriorityQueue *pq, ActionStack *stack) {
    int id, typeChoice, severity, loc;

    printf("Enter Incident ID: ");
    scanf("%d", &id);

    printf("Select Incident Type:\n");
    printf("1. Medical\n2. Fire\n3. Crime\n4. Utility\n");
    printf("Enter choice: ");
    scanf("%d", &typeChoice);

    if (typeChoice < 1 || typeChoice > 4) {
        printf("Invalid type choice.\n");
        return;
    }

    printf("Enter Severity (1-10, higher = more severe): ");
    scanf("%d", &severity);

    printf("Enter Location Code (integer): ");
    scanf("%d", &loc);

    insertIncident(pq, id, typeChoice, severity, loc);
    printf("Incident %d reported and stored in priority queue.\n", id);

    char desc[DESC_LEN];
    snprintf(desc, DESC_LEN, "INCIDENT_REPORTED %d", id);
    pushAction(stack, desc);
}

/* B. Assign Emergency Unit */
void assignEmergencyUnit(PriorityQueue *pq, UnitNode *unitHead, ActionStack *stack) {
    if (unitHead == NULL) {
        printf("No units in the system.\n");
    }

    Incident *inc = getHighestPriorityPending(pq);
    if (inc == NULL) {
        printf("NO PENDING INCIDENTS.\n");
        return;
    }

    int requiredUnitType = requiredUnitForIncidentType(inc->type);
    UnitNode *unit = searchFirstAvailableUnitByType(unitHead, requiredUnitType);

    if (unit == NULL) {
        printf("NO UNITS AVAILABLE – INCIDENT QUEUED (Incident ID: %d)\n", inc->incident_id);
        return;
    }

    /* Assign */
    inc->status = STATUS_ASSIGNED;
    unit->status = UNIT_BUSY;

    printf("Assigned Incident %d (%s) to Unit %d (%s).\n",
           inc->incident_id,
           incidentTypeToString(inc->type),
           unit->unit_id,
           unitTypeToString(unit->unit_type));

    char desc[DESC_LEN];
    snprintf(desc, DESC_LEN, "INCIDENT_ASSIGNED %d -> %d", inc->incident_id, unit->unit_id);
    pushAction(stack, desc);
}

/* C. Update Severity */
void updateSeverity(PriorityQueue *pq, ActionStack *stack) {
    int id, newSeverity;
    printf("Enter Incident ID to update severity: ");
    scanf("%d", &id);

    Incident *inc = findIncidentById(pq, id);
    if (inc == NULL) {
        printf("Incident ID %d not found.\n", id);
        return;
    }

    printf("Current severity: %d\n", inc->severity);
    printf("Enter NEW severity (1-10): ");
    scanf("%d", &newSeverity);

    inc->severity = newSeverity;
    printf("Severity updated for Incident %d.\n", id);

    char desc[DESC_LEN];
    snprintf(desc, DESC_LEN, "SEVERITY_UPDATED %d", id);
    pushAction(stack, desc);
}

/* D. Resolve Incident */
void resolveIncident(PriorityQueue *pq, UnitNode *unitHead, ActionStack *stack) {
    int incidentId, unitId;
    printf("Enter Incident ID to mark as RESOLVED: ");
    scanf("%d", &incidentId);
    printf("Enter Unit ID to release (mark AVAILABLE): ");
    scanf("%d", &unitId);

    Incident *inc = findIncidentById(pq, incidentId);
    if (inc == NULL) {
        printf("Incident ID %d not found.\n", incidentId);
    } else {
        inc->status = STATUS_RESOLVED;
        printf("Incident %d marked as RESOLVED.\n", incidentId);
        char desc1[DESC_LEN];
        snprintf(desc1, DESC_LEN, "INCIDENT_RESOLVED %d", incidentId);
        pushAction(stack, desc1);
    }

    UnitNode *unit = searchUnitById(unitHead, unitId);
    if (unit == NULL) {
        printf("Unit ID %d not found.\n", unitId);
    } else {
        unit->status = UNIT_AVAILABLE;
        printf("Unit %d marked as AVAILABLE.\n", unitId);
        char desc2[DESC_LEN];
        snprintf(desc2, DESC_LEN, "UNIT_RELEASED %d", unitId);
        pushAction(stack, desc2);
    }
}

/* E. Display System State */
void displaySystemState(PriorityQueue *pq, UnitNode *unitHead, ActionStack *stack) {
    printf("\n=========== SYSTEM STATE ===========\n");
    printf("\n--- Priority Queue (PENDING only) ---\n");
    displayPriorityQueue(pq);

    printf("\n--- All Incidents (for reference) ---\n");
    displayAllIncidents(pq);

    printf("\n--- Units (Linked List) ---\n");
    displayUnits(unitHead);

    printf("\n--- Action Stack ---\n");
    displayStack(stack);

    printf("====================================\n");
}

/* ---------- MENU FOR UNIT OPERATIONS ---------- */

void addUnitMenu(UnitNode **unitHead) {
    int id, typeChoice;
    printf("Enter Unit ID: ");
    scanf("%d", &id);

    printf("Select Unit Type:\n");
    printf("1. Ambulance\n2. FireTruck\n3. PatrolCar\n4. UtilityTeam\n");
    printf("Enter choice: ");
    scanf("%d", &typeChoice);

    if (typeChoice < 1 || typeChoice > 4) {
        printf("Invalid unit type choice.\n");
        return;
    }

    insertUnit(unitHead, id, typeChoice);
}

void searchUnitByTypeMenu(UnitNode *head) {
    int typeChoice;
    printf("Select Unit Type to search:\n");
    printf("1. Ambulance\n2. FireTruck\n3. PatrolCar\n4. UtilityTeam\n");
    printf("Enter choice: ");
    scanf("%d", &typeChoice);

    if (typeChoice < 1 || typeChoice > 4) {
        printf("Invalid unit type choice.\n");
        return;
    }

    printf("Units with type %s:\n", unitTypeToString(typeChoice));
    UnitNode *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->unit_type == typeChoice) {
            printf("UnitID: %d, Status: %s\n",
                   temp->unit_id,
                   unitStatusToString(temp->status));
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No units of this type.\n");
    }
}

/* ---------- MAIN ---------- */

int main() {
    PriorityQueue pq;
    UnitNode *unitHead = NULL;
    ActionStack stack;

    initPriorityQueue(&pq);
    initStack(&stack);

    int choice;
    while (1) {
        printf("\n========== EMERGENCY DISPATCH SYSTEM ==========\n");
        printf("1. Report New Incident\n");
        printf("2. Assign Emergency Unit\n");
        printf("3. Update Incident Severity\n");
        printf("4. Resolve Incident\n");
        printf("5. Display System State\n");
        printf("6. Add Emergency Unit\n");
        printf("7. Search Units by Type\n");
        printf("8. Pop Last Action (view undo)\n");
        printf("9. Display Action Log\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                reportNewIncident(&pq, &stack);
                break;
            case 2:
                assignEmergencyUnit(&pq, unitHead, &stack);
                break;
            case 3:
                updateSeverity(&pq, &stack);
                break;
            case 4:
                resolveIncident(&pq, unitHead, &stack);
                break;
            case 5:
                displaySystemState(&pq, unitHead, &stack);
                break;
            case 6:
                addUnitMenu(&unitHead);
                break;
            case 7:
                searchUnitByTypeMenu(unitHead);
                break;
            case 8: {
                Action a;
                if (popAction(&stack, &a)) {
                    printf("Popped action (no real undo): %s\n", a.description);
                }
                break;
            }
            case 9:
                displayStack(&stack);
                break;
            case 0:
                printf("Exiting system.\n");
                /* Free linked list memory */
                while (unitHead != NULL) {
                    UnitNode *tmp = unitHead;
                    unitHead = unitHead->next;
                    free(tmp);
                }
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}