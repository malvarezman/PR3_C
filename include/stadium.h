/*
* File: stadium.h
* Author: UOC
* Course: 20231
* Description: PRA3
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_LINE 514
#define MAX_FILENAME_LENGTH 15+1
#define MAX_NAME_LENGTH 15+1 

#define MAX_SUPPORTERS   10  /* Max. supporters */
#define MAX_TICKETS      10  /* Max. tickets per supporter */
#define MAX_EVENTS_TYPE   3  /* Max. events type */

/* User defined types */
/* Error type */
typedef enum {OK = 0, ERR_CANNOT_READ = -1, ERR_MEMORY = -2, ERR_NOT_FOUND = -3} tError;

/* Event type */
typedef enum {FOOTBALL_MATCH = 1, CONCERT, EXPO} tEventType;

/* Ticket */
typedef struct {
	tEventType eventType;
	float price;	
} tTicket;

/* Ticket table */
typedef struct {
	tTicket table[MAX_TICKETS];
	int nTickets;
} tTicketTable;

/* Supporter */
typedef struct {
	int id;
	char name[MAX_NAME_LENGTH];
	int age;
	int membershipYears;
	tTicketTable tickets;
} tSupporter;

/* Suporter table */
typedef struct {
	tSupporter table[MAX_SUPPORTERS];
	int nSupporters;
} tSupporterTable;

/* Auxiliary Actions */
/* Load supporters's table from file */
void supportersTableLoad(tSupporterTable *tabSupporters, const char* filename, tError *retVal);
/* Write a tab supporters */
void writeTabSupporters(tSupporterTable tabSupporters);
/* Select a supporter from a table supporters by ID */
void selectSupporter (tSupporterTable tabSupporters, int supporterId, tSupporter *supporter, tError *retVal);
/* Write a ticket */
void writeTicket(tTicket ticket);

/* Exercices */
/* Exercise 2.1 */
void supporterTableInit(tSupporterTable *tabSupporters);
/* Exercise 2.2 */
void supporterTableAdd(tSupporterTable *tabSupporters, tSupporter supporter, tError *retVal);
/* Exercise 2.3 */
float averageSpendingByEvent (tSupporter supporter, tEventType eventType);

