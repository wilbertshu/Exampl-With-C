#include <stdio.h> // printf,scanf()
#include <string.h> //strcmp , strcpy
#include <windows.h> // Sleep()
#include <time.h> //time
#define LEN 150

FILE * information;
long point[9];
char my_name[30], employee[10][50], redeem_item[9][50], buf[LEN];
time_t curtime;
struct tm *loc_time;

/* ----  All Functions used in this program ----  */
void name_ask();
void main_menu();
void customer();
void add_customer();
void edit_customer();
void view_customer();
void reward();
void assign_reward();
void add_reward();
void redeem_reward();
void get_reward();
void gift_reward();
void top_customer();
void exit_program();

/* ----  Start Program ----  */
void main() {
	curtime = time(NULL);
	loc_time = localtime(&curtime);
	name_ask();
}

/* ----  Simple ask name ----  */
void name_ask() {
	printf("This program is open at:\n");
	strftime(buf, LEN, "Date: %A, %b %d %Y\n", loc_time);
	fputs(buf, stdout);
	strftime(buf, LEN, "Time: %I:%M %p\n", loc_time);
	fputs(buf, stdout);
	printf("-----------------------------------------------------------------\n");
	printf("Hello, What is your name?: ");
	gets(my_name);
	printf("\n");
	/*-- File Open --*/
	information = fopen("UserInformation.txt", "w+");
	fprintf(information, "Username : ");
	fprintf(information,"%s\n",my_name);
	fprintf(information, "================================\n");
	fprintf(information, "History: \n");
	fprintf(information, "================================\n");
	fclose(information);
	/*-- File Close*/
	printf("-----------------------------------------------------------------\n");
	printf("Your Program is Loading . . .\n");
	printf("-----------------------------------------------------------------\n");
	printf("		Compiling Your Program . . .\n");
	for (int i = 1; i <= 60; i++) {
		printf("\b\b\b\b\b# %3d%%", i);
		Sleep(100);
	}
	printf("\n");
	printf("-----------------------------------------------------------------\n");
	printf("                        ------Message-----\n");
	printf("                       |Loading Completed!|\n");
	printf("                        --------Box-------\n");
	system("pause>nul");
	system("cls");
	main_menu();
}

// ----  Shows Main Menu
void main_menu() {
	int choice;
	printf("  Hello: %s\n", my_name);
	printf("  =================================\n");
	printf("||Welcome to Palm Department Store ||\n");
	printf("  =================================\n");
	printf("  Which section would you like to go?:\n");
	printf("  1. Customer\n");
	printf("  2. Reward\n");
	printf("  3. View Top Customer\n");
	printf("  4. Exit Program\n");
	printf("  Enter your choice: ");
	scanf(" %d", &choice);
	switch (choice) {
	case 1:
		system("cls");
		customer();
		break;
	case 2:
		system("cls");
		reward();
		break;
	case 3:
		system("cls");
		top_customer();
		break;
	case 4:
		system("cls");
		exit_program();
		break;
	default:
		printf("    ---Message---\n");
		printf("   |Invalid Input|\n");
		printf("    -----Box-----\n");
		getch();
		system("cls");
		main_menu();
		break;
	}
}
// ----  Shows Customer Menu
void customer() {
	int choice;
	printf("  Hello: %s\n", my_name);
	printf("  ==================================\n");
	printf("||Welcome, This is the Customer Menu||\n");
	printf("  ==================================\n");
	printf("  What would you like to do: \n");
	printf("  1. Add New/Reset Customer\n");
	printf("  2. Edit Customer Detail\n");
	printf("  3. View Customer Detail\n");
	printf("  4. Back\n");
	printf("  Enter your choice: ");
	scanf(" %d", &choice);
	switch (choice) {
	case 1:
		system("cls");
		add_customer();
		break;
	case 2:
		system("cls");
		edit_customer();
		break;
	case 3:
		system("cls");
		view_customer();
		break;
	case 4:
		system("cls");
		main_menu();
		break;
	default:
		printf("\n");
		printf("    ---Message---\n");
		printf("   |Invalid Input|\n");
		printf("    -----Box-----\n");
		getch();
		system("cls");
		customer();
		break;
	}
}

// ----  Add Customer
void add_customer() {
	int i, choice, choice_reset;
	printf("  =====================\n");
	printf(" |Customer Registration|\n");
	printf("  =====================\n");
	printf("*Before adding\n");
	printf("*Have you added your customer before?\n");
	printf("*You can only add for one time, so add wisely :)\n");
	printf("*If you want to add more customer, do reset and re-add again\n");
	printf("*You can add up to 10 customers\n");
	printf("*If you have added, do use the edit customer\n");
	printf(" 1. Understand\n");
	printf(" 2. Back\n");
	printf(" 3. Reset all Customers\n");
	printf(" Enter choice: ");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		if (employee[0][0] != NULL) {
			printf("-----------Message-----------\n");
			printf("|You have added Your Customer|\n");
			printf("-------------Box-------------\n");
			getch();
		}
		else {
			system("cls");
			printf("  =====================\n");
			printf(" |Customer Registration|\n");
			printf("  =====================\n");
			printf("You can only add up to 10 Customer in a meanwhile\n");
			printf("To stop adding please type 'x' \n");
			for (i = 0; strcmp(employee[i], "") == 0 && i < 10; i++) {
				printf("%d.Enter name: ", i);
				scanf(" %[^\n]s", employee[i]);
				if (strcmp(employee[i], "x") == 0) {
					i++;
					break;
				}
				/*File Open*/
				information = fopen("UserInformation.txt", "a+");
				fprintf(information, "Customer %d Name : ", i);
				fprintf(information, "%s\n", employee[i]);
				fclose(information);
				/*File Close*/
			}
			if (i != 10) {
				strcpy(employee[--i], "");
			}
		}
		break;
	case 2:
		break;
	case 3: 
		printf("\n");
		printf(" Are you sure to reset all?\n");
		printf(" 1. Yes\n");
		printf(" 2. No\n");
		printf(" Enter Choice: ");
		scanf("%d", &choice_reset);
		switch (choice_reset) {
		case 1:
			for (i = 0; i < 10; i++) {
				strcpy(employee[i], ""); // used for inserting "" string
				point[i] = 0;
				strcpy(redeem_item[i], "");
			}
			printf(" All customers have been reset!\n");
			getch();
			system("cls");
			add_customer();
			break;
		case 2:
			printf("Going back to menu..\n");
			getch();
			system("cls");
			main_menu();
			break;
		default:
			printf("\n");
			printf("    ---Message---\n");
			printf("   |Invalid Input|\n");
			printf("    -----Box-----\n");
			getch();
			system("cls");
			add_customer();
			break;
		}
	default:
		printf("\n");
		printf("    ---Message---\n");
		printf("   |Invalid Input|\n");
		printf("    -----Box-----\n");
		getch();
		system("cls");
		add_customer();
		break;
	}
	system("cls");
	customer();
}

// ----  Edit Customer Details
void edit_customer() {
	int i, cust_no;
	printf("  =======================\n");
	printf("||Customer Customization ||\n");
	printf("  =======================\n");
	if (employee[0][0] == NULL) {
		printf(" ------------Message--------------\n");
		printf("|You havent added any customer yet|\n");
		printf(" --------------Box----------------\n");
		getch();
	}
	else
	{
		for (i = 0; i < 10; i++) {
			if (employee[i][0] == NULL) {
				break;
			}
			printf("%d. Customer Name: %s\n", i, employee[i]);
			
		}
			printf("10. Back\n");
			printf("Which Customer would you like you edit\n");
			printf("To cancel editing please enter '10' : ");
			scanf("%d", &cust_no);
			if (cust_no >= 0 && cust_no < 10) {
				if (employee[cust_no][0] == NULL) {
					printf("   --------Message-------\n");
					printf("  |Name is not registered|\n");
					printf("   ----------Box---------\n");
					getch();
					system("cls");
					edit_customer();
				}
				printf("%d. Enter The new Customer Name: ", cust_no);
				scanf("%s", employee[cust_no]);
				/*File Open*/
				information = fopen("UserInformation.txt", "a");
				fprintf(information, "================================\n");
				fprintf(information, "Edited Customer %d: %s\n", cust_no, employee[cust_no]);
				fclose(information);
				/*File Closed*/
				printf("Successfully changed!\n");
				printf("%d.New Customer Name: %s", cust_no, employee[cust_no]);
			}
			else if (cust_no == 10) {
				printf("    ------Message-----\n");
				printf("   |Going back to Menu|\n");
				printf("    --------Box-------\n");
				getch();
				system("cls");
				customer();

			}
		
		else {
			printf("\n");
			printf("    ------Message-----\n");
			printf("   |Customer Not Found|\n");
			printf("    --------Box-------\n");
			getch();
			system("cls");
			edit_customer();
		}
	}
	getch();
	system("cls");
	customer();
}

// ----  View Customer Details
void view_customer() {
	int i, choice;
	printf("  ===================\n");
	printf("||Your Customer Lists||\n");
	printf("  ===================\n");
	if (employee[0][0] == NULL) {
		printf(" --------------Message------------\n");
		printf("|You havent added any customer yet|\n");
		printf(" ----------------Box--------------\n");
		getch();
	}
	else {
		for (i = 0; i < 10; i++) {
			if (employee[i][0] == NULL) {
				break;
			}
			else {
				printf("%d.Name: %s \nPoint: %ld \nItem Redeemed : %s\n\n", i, employee[i], point[i], redeem_item[i]);			
			}
		}
		printf("\n");
	}
	printf("Back to Customer menu?\n");
	printf("1.Back\n");
	printf("Enter Your Choice: ");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		system("cls");
		customer();
		break;
	default:
		printf("\n");
		printf("    ---Message---\n");
		printf("   |Invalid Input|\n");
		printf("    -----Box-----\n");
		getch();
		system("cls");
		view_customer();
	}
}

// ----  View Reward Menu
void reward() {
	int choice;
	printf("  Hello: %s\n", my_name);
	printf("  ================================\n");
	printf("||Welcome, This is the Reward Menu||\n");
	printf("  ================================\n");
	printf("  What would you like to do: \n");
	printf("  1. Assigned Reward for Customer\n");
	printf("  2. Additional Reward to Customer \n");
	printf("  3. Redeem Reward to Customer \n");
	printf("  4. View Available Gifts \n");
	printf("  5. Back\n");
	printf("  Enter your choice: ");
	scanf(" %d", &choice);
	switch (choice) {
	case 1:
		system("cls");
		assign_reward();
		break;
	case 2:
		system("cls");
		add_reward();
		break;
	case 3:
		system("cls");
		redeem_reward();
		break;
	case 4:
		system("cls");
		gift_reward();
		break;
	case 5:
		system("cls");
		main_menu();
		break;
	default:
		printf("\n");
		printf("    ---Message---\n");
		printf("   |Invalid Input|\n");
		printf("    -----Box-----\n");
		getch();
		system("cls");
		reward();
		break;
	}
}

// ----  Assign First reward point to customer Menu
void assign_reward() {
	int i;
	printf("  =================\n");
	printf("||Assign Point Menu||\n");
	printf("  =================\n");
	if (employee[0][0] == NULL) {
		printf(" -------------Message-------------\n");
		printf("|You havent added any customer yet|\n");
		printf(" ---------------Box---------------\n");
		getch();
	}
	else if (point[0] != NULL) {
		printf(" ---------------Message--------------\n");
		printf("|You have receive your monthly salary|\n");
		printf(" ----------------Box-----------------\n");
		getch();
	}
	else {
		printf("How much does this customer get for the monthly salary?\n");
		printf("To receive point minimal Salary is RM 10+\n");
		information = fopen("UserInformation.txt", "a");
		/*File Open*/
		fprintf(information, "================================\n");
		for (i = 0; i < 10; i++) {
			if (employee[i][0] == NULL) {
				printf("   ------Message------\n");
				printf("  |Successfully Added!|\n");
				printf("   --------Box--------\n");
				getch();
				system("cls");
				reward();
			}
			printf("%d.Name: %s\n", i, employee[i]);
			printf("%d.Monthly Salary : RM ", i);
			scanf(" %ld", &point[i]);
			point[i] = point[i] / 10;
			printf("%s Earned %d Points\n",employee[i], point[i]);
			fprintf(information, "Point For Customer %d : %ld\n", i, point[i]);
			printf("\n");
		}
		fclose(information);
		/*File Close*/
	}
	system("cls");
	reward();
	getch();
}

// ---- Add Additional Reward Point to Customers
void add_reward() {
	int i, choice, add = 0;
	printf("  ===================\n");
	printf("||Add More Point Menu||\n");
	printf("  ===================\n");
	if (employee[0][0] == NULL) {
		printf(" -------------Message-------------\n");
		printf("|You havent added any customer yet|\n");
		printf(" ---------------Box---------------\n");
		getch();
	}
	else if (point[0] == NULL) {
		printf(" ---------------Message--------------\n");
		printf("|You have receive your monthly salary|\n");
		printf(" ----------------Box-----------------\n");
		getch();
	}
	else {
		for (i = 0; i < 10; i++) {
			if (employee[i][0] == NULL) {
				break;
			}
			else {
				printf("%d.Name: %s \nPoint: %ld\n\n", i, employee[i], point[i]);
			}
		}
		printf("10. Back\n");
		printf("\n");
		printf("Which Customer would you like to add the point?\n");
		printf("To receive point minimal Salary is RM 10+\n");
		printf("Enter Choice: ");
		scanf("%d", &choice);
		if (employee[choice][0] == NULL) {
			printf("   --------Message-------\n");
			printf("  |Name is not registered|\n");
			printf("   ----------Box---------\n");
			getch();
			system("cls");
			add_reward();
		}
		else if (choice == 10) {
			reward();
		}
		else {
			information = fopen("UserInformation.txt", "a");
			/*File Open*/
			printf("How much would you like to Add?\n");
			printf("Additional Salary : RM ");
			scanf("%ld", &add);
			add = add / 10;
			fprintf(information, "================================\n");
			fprintf(information, "Added %d Point to Customer : %s\n", add, employee[choice]);
			fclose(information);
			/*File Close*/
			point[choice] = point[choice] + add;
			printf("%d Point Added!\n", add);
		}
	}
	getch();
	system("cls");
	reward();
}
// ----  Customer Redeem Reward Menu
void redeem_reward() {
	int i, choice;
	printf("  =============\n");
	printf("||Redeem Reward||\n");
	printf("  =============\n");
	if (employee[0][0] == NULL) {
		printf(" -------------Message-------------\n");
		printf("|You havent added any customer yet|\n");
		printf(" ---------------Box---------------\n");
		getch();
	}
	else {
		get_reward();
	}
	getch();
	system("cls");
	reward();
}


void get_reward() {
	int i, choice, redeem;
	for (i = 0; i < 10; i++) {
		if (employee[i][0] == NULL) {
			break;
		}
		else {
			printf("\n%d.Customer Name: %s\n", i, employee[i]);
			printf("You have %ld points\n", point[i]);
		}
	}
	printf("\n");
	printf("10. Back");
	printf("\n");
	printf("Which customer to redeem?\n");
	printf("Enter your customer number : ");
	scanf("%d", &choice);
	if (choice >= 0 && choice < 10) {
		if (redeem_item[choice][0] == NULL) { // if null
			if (employee[choice][0] == NULL) {
				printf(" ------------------Message----------------\n");
				printf("|Customer is not registered on that number|\n");
				printf(" --------------------Box------------------\n");
				getch();
				system("cls");
				redeem_reward();
			}
			else {
				printf("\nCustomer Name: %s\n", employee[choice]);
				printf("You have %ld points\n", point[choice]);
				printf("\n");
				system("pause");
			}
			system("cls");
			printf("  =============\n");
			printf("||Redeem Reward||\n");
			printf("  =============\n");
			printf("1. Kijang Innova      - 30000 points\n");
			printf("2. RM 5000            - 12500 points\n");
			printf("3. Asus ROG 950M GTX  - 11000 points\n");
			printf("4. Samsung S7 Edge    - 10000 points\n");
			printf("5. Tupperware         - 3000  points\n");
			printf("6. Lucky Coupon x15   - 10    points\n");
			printf("\n");
			printf("Which item will you redeem?\n");
			printf("Number: ");
			scanf("%d", &redeem);
			switch (redeem) {
			case 1:
				if (point[choice] < 30000) {
					printf("Insufficient Point\n");
					printf("Please choose Customer which has enough point\n");
					getch();
					system("cls");
					redeem_reward();
				}
				else if (point[choice] >= 30000) {
					point[choice] = point[choice] - 30000;
					printf("Redeem Succesfully!\n");
					information = fopen("UserInformation.txt", "a");
					strcpy(redeem_item[choice], "Kijang Innova");
					/*File Open*/
					fprintf(information, "================================\n");
					fprintf(information, "Customer %d Redeemed: %s\n", choice, redeem_item[choice]);
					fclose(information);
					/*File Close*/
					getch();
				}
				break;
			case 2:
				if (point[choice] < 12500) {
					printf("Insufficient Point\n");
					printf("Please choose Customer which has enough point\n");
					getch();
					system("cls");
					redeem_reward();
				}
				else if (point[choice] >= 12500) {
					point[choice] = point[choice] - 12500;
					printf("Redeem Succesfully!\n");
					information = fopen("UserInformation.txt", "a");
					strcpy(redeem_item[choice], "RM 5000");
					/*File Open*/
					fprintf(information, "================================\n");
					fprintf(information, "Customer %d Redeemed: %s\n", choice, redeem_item[choice]);
					fclose(information);
					/*File Close*/
					getch();
				}
				break;
			case 3:
				if (point[choice] < 11000) {
					printf("Insufficient Point\n");
					printf("Please choose Customer which has enough point\n");
					getch();
					system("cls");
					redeem_reward();
				}
				else if (point[choice] >= 11000) {
					point[choice] = point[choice] - 11000;
					printf("Redeem Succesfully!\n");
					information = fopen("UserInformation.txt", "a");
					strcpy(redeem_item[choice], "Asus ROG 950M GTX");
					/*File Open*/
					fprintf(information, "================================\n");
					fprintf(information, "Customer %d Redeemed: %s\n", choice, redeem_item[choice]);
					fclose(information);
					/*File Close*/
					getch();
				}
				break;
			case 4:
				if (point[choice] < 10000) {
					printf("Insufficient Point\n");
					printf("Please choose Customer which has enough point\n");
					getch();
					system("cls");
					redeem_reward();
				}
				else if (point[choice] >= 10000) {
					point[choice] = point[choice] - 10000;
					printf("Redeem Succesfully!\n");
					information = fopen("UserInformation.txt", "a");
					strcpy(redeem_item[choice], "Samsung S7 Edge");
					/*File Open*/
					fprintf(information, "================================\n");
					fprintf(information, "Customer %d Redeemed: %s\n", choice, redeem_item[choice]);
					fclose(information);
					/*File Close*/
					getch();
				}
				break;
			case 5:
				if (point[choice] < 3000) {
					printf("Insufficient Point\n");
					printf("Please choose Customer which has enough point\n");
					getch();
					system("cls");
					redeem_reward();
				}
				else if (point[choice] >= 3000) {
					point[choice] = point[choice] - 3000;
					printf("Redeem Succesfully!\n");
					information = fopen("UserInformation.txt", "a");
					strcpy(redeem_item[choice], "Tupperware");
					/*File Open*/
					fprintf(information, "================================\n");
					fprintf(information, "Customer %d Redeemed: %s\n", choice, redeem_item[choice]);
					fclose(information);
					/*File Close*/
					getch();
				}
				break;
			case 6:
				if (point[choice] < 10) {
					printf("Insufficient Point\n");
					printf("Please choose Customer which has enough point\n");
					getch();
					system("cls");
					redeem_reward();
				}
				else if (point[choice] >= 10) {
					point[choice] = point[choice] - 10;
					printf("Redeem Succesfully!\n");
					information = fopen("UserInformation.txt", "a");
					strcpy(redeem_item[choice], "Lucky Coupon x15");
					/*File Open*/
					fprintf(information, "================================\n");
					fprintf(information, "Customer %d Redeemed: %s\n", choice, redeem_item[choice]);
					fclose(information);
					/*File Close*/
					getch();
				}
				break;
			default:
				printf("\n");
				printf("    ---Message---\n");
				printf("   |Invalid Input|\n");
				printf("    -----Box-----\n");
				getch();
				system("cls");
				redeem_reward();
			}
		}
		else {
			printf("Customer has redeem reward! \n");
			printf("*You can only Redeem 1 items :) \n");
			getch();
			system("cls");
			redeem_reward();
		}
	}
	else if (choice == 10) {
		printf("    -----Message------\n");
		printf("   |Going back to Menu|\n");
		printf("    -------Box--------\n");
		getch();
		system("cls");
		customer();
	}
	else {
		printf("    -----Message-----\n");
		printf("   |No Customer Found|\n");
		printf("    -------Box-------\n");
		system("pause");
		system("cls");
		redeem_reward();
	}
}
// ----  Shows Reward Lists
void gift_reward() {
	int ask_gift;
	printf("  ==========\n");
	printf("||Gift Lists||\n");
	printf("  ==========\n");
	printf("  1. Car \n");
	printf("  2. Cash \n");
	printf("  3. Laptop \n");
	printf("  4. Mobile \n");
	printf("  5. Tupperware \n");
	printf("  6. Lucky Coupon \n");
	printf("\n");	
	printf("  Go back? \n");
	printf("  0. Back\n");
	printf("  Enter Your Choice: ");
	scanf(" %d", &ask_gift);
	switch (ask_gift) {
	case 0:
		system("cls");
		reward();
		break;
	default:
		printf("\n");
		printf("    ---Message---\n");
		printf("   |Invalid Input|\n");
		printf("    -----Box-----\n");
		getch();
		system("cls");
		gift_reward();
		break;
	}
}

// ----  Shows Top Customer which has Big Point
void top_customer() {
	int i;
	int emp_max, emp_min;
	emp_max = emp_min = 0;
	long max_num, min_num;
	max_num = min_num = point[0];

	printf("  ============\n");
	printf("||Top Customer||\n");
	printf("  ============\n");
	if (employee[0][0] == NULL) {
		printf(" -------------Message-------------\n");
		printf("|You havent added any customer yet|\n");
		printf(" ---------------Box---------------\n");
		getch();
		system("cls");
		main_menu();
	}
	else {
		if (point[0] == NULL) {
			MessageBox(0, "Add points to the Customer to view this~", "No Points Added", MB_ICONEXCLAMATION);
		}
		else if (point[0] != NULL) {
			for (i = 0; i < point[i] != NULL; i++) {
				if (point[i] > max_num) {
					max_num = point[i];
					emp_max = i;
				}
				if (point[i] < max_num) {
					min_num = point[i];
					emp_min = i;
				}
			}
			
			printf("\n"); // Name of the customers havent
			information = fopen("UserInformation.txt", "a");
			/*File Open*/
			printf("  ------------------Message--------------------\n");
			printf("   %s Has the highest point : %ld\n", employee[emp_max], max_num);
			fprintf(information, "================================\n");
			fprintf(information, "Top Customer is : %s !\n", employee[emp_max]);
			printf("\n");
			printf("   %s Has the lowest point  : %ld\n", employee[emp_min], min_num);
			fprintf(information, "Customer which has the lowest Point : %s \n", employee[emp_min]);
			fclose(information);
			printf("  -------------------Box------------------------\n");
			/*File Close*/
			getch();
		}
	}
	system("cls");
	main_menu();
}

// ----  Ends Program
void exit_program() {
	int choice;

	printf(" =============\n");
	printf("||Exit Program||\n");
	printf("  ============\n"); 
	printf("  Do you wish to exit this program?\n");
	printf("  1. Yes \n");
	printf("  2. No \n");
	printf("  Enter Choice: ");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		MessageBox(0, "Exiting Program","Goodbye, See You Again", MB_ICONINFORMATION);
		exit(0);
		break;
	case 2:
		system("cls");
		main_menu();
	default:
		printf("\n");
		printf("    ---Message---\n");
		printf("   |Invalid Input|\n");
		printf("    -----Box-----\n");
		getch();
		system("cls");
		main_menu();
		break;
	}
}