#include <stdio.h>
#include <string.h>
#include "stadium.h"

int main(int argc, char **argv)
{
	tSupporterTable tabSupporters;
	tSupporter supporter;
    tEventType selectEventType;
	char filename[MAX_FILENAME_LENGTH];
	tError retVal;	
	int supporterId;
	int i;
	
	/* Exercise 2.4 */	
	/* Supporters table initialization */
	supporterTableInit(&tabSupporters);
	/* load data from file*/ 
    printf("LOAD DATA FROM FILE. ENTER FILE NAME:\n");
    scanf("%s", filename);
    supportersTableLoad(&tabSupporters, filename, &retVal);
	/* Data processing */
    if (retVal == OK) {	
		/* Show supporters list loaded */
		writeTabSupporters(tabSupporters);    }
    else {
        printf("NO SUPPORTER RECOVERED");
        return 0;
    }
		/* Exercise 2.5 */
		/* Select a supporter by ID */
		/* Data input */
		printf("SELECT SUPPORTER (ID):\n");
		scanf("%d", &supporterId);
		/* Recover supporter's ticket list */		
        selectSupporter(tabSupporters, supporterId, &supporter, &retVal);
		
		/* Show the list of supporter's tickets and the average spending of the selected event */
		if (retVal == OK) {			
			for (i = 0; i < supporter.tickets.nTickets; i++){
                writeTicket(supporter.tickets.table[i]);
			}	
			printf("\n");
			/* Select a event type */
            printf("SELECT EVENT (1-FOOTBALL MATCH, 2-CONCERT, 3-EXPO): \n");		
            scanf("%d",&selectEventType);
        
            printf("AVERAGE SPENDING: %.2f", averageSpendingByEvent(supporter, selectEventType));
		}
		else {
            printf("NO SUPPORTER RECOVERED");
            return 0;
		}
		
	return 0;
}

