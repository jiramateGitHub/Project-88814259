#include<stdio.h>
#include<string.h>
#include<time.h>

struct DATA{ //
	char id[9];
	char nname[40];
	char lname[40];	
	int age;
};

struct TESTGRADE{ //
	int incode;
	int credit;
	float ggpa;
};

/*+++++++++ menu +++++++++*/
void main_menu(void); //
void login(void); //
void login_admins(void); //
void main_admin(void); //
void profile_view(void); //

/*+++++++++ view +++++++++*/
void faculty_view(void); //
void ex_code(void); //
void gpa(void); //
void clear_view(void); //

/* +++++++++ FILE +++++++++ */
void view_gpa(void); //
void show_sumgpa(void); //
void usertest_gpa(void); //
void list_idnisit(void); //
void login_date(void); //
void reg_date(void); //
void view_total_reg(void); //

/*+++++++++ input ++++++++*/
int register_nisit(void); //
void clear_data(void); //
void total_user(void); //
void total_reg(void); //

int main(int argc, char * argv[]){
	/* +++++++++ struct +++++++++ */ 
	struct DATA nisit[9999];
	struct TESTGRADE reg[999];
	
	int menu_n,text,login_n; // case2
	char check_id[9],check_id1[9]; //case2
	int checkww=0; //case2
	int i,duk;
	/*++++++ Process GPA ++++++*/
	int amount_code,sum_credit=0;
	int input_grade[99];
	float sum_grade[99],ans=0,sum_gpa=0;
	
	/* ++++++++++ FILE ++++++++++ */
	FILE*log_id;
	FILE*code1;
	FILE*log_time;
	FILE*login_admin;
	FILE*test_gpa;
	/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	total_user();
    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	int choice;
	do{
		main_menu();	
		printf("\nPlease Choose Menu : ");
		scanf("%d",&choice);
		switch(choice){
			case 1: /* Register */
					register_nisit();
			break;	
			
			case 2: /* Login Nisit */
					log_id = fopen("id_login.txt","r");
					log_time = fopen("date/date_login.txt","a");
					login();
					scanf("%s",&check_id);
					while(fscanf(log_id, "%s",check_id1) != EOF){
    					if((strcmp(check_id,check_id1) == 0)){
    						time_t rawtime;
 							time (&rawtime);
    						printf("---> ID Nist is True. : %s \n",ctime(&rawtime));
    						checkww++;
    						time_t rawtime2;
 							time (&rawtime2);
 							fprintf(log_time,"ID : %s \n",check_id);
    						fprintf(log_time,"Date Login : %s",ctime(&rawtime2));
    						fprintf(log_time,"---------------------------------------\n");
    						fclose(log_time);	
    					do{
    						profile_view();
    						printf("\nID Nisit : %s",check_id);
    						printf("\n_________________________________________\n");
							printf("\nPlease Choose Menu : ");
							scanf("%d",&menu_n);
							/* Grade test */
							if(menu_n == 1){
								duk = 1;
								sum_grade[i] = 0;
								sum_credit = 0;
								sum_gpa = 0;
								test_gpa = fopen("test_grade.txt","w");
								printf("\nInput Amount Registration Code : ");
								scanf("%d",&amount_code);
								ex_code();
								for(i=0;i<amount_code;i++){
									printf("\n[%d] Input Registration Code (Ex.-> 99910259) : ",i+1);
									scanf("%d",&reg[i].incode);
									fprintf(test_gpa,"[%d] Subject code: %d | ",i+1,reg[i].incode);
									printf("    Input Credit (Ex.-> 3) : ");
									scanf("%d",&reg[i].credit);
									fprintf(test_gpa,"Credit: %d | ",reg[i].credit);
									view_gpa();
									printf("    Input Grade (1-8) : ");
									scanf("%d",&input_grade[i]);
									if(input_grade[i] <= 8 && input_grade[i] >= 1){
									if(input_grade[i] == 1){ //A
										reg[i].ggpa = 4.00;
										fprintf(test_gpa,"Grade: A \n");
									}
									if(input_grade[i] == 2){ //B+
										reg[i].ggpa = 3.50;
										fprintf(test_gpa,"Grade: B+ \n");
									}
									if(input_grade[i] == 3){ //B
										reg[i].ggpa = 3.00;
										fprintf(test_gpa,"Grade: B \n");
									}
									if(input_grade[i] == 4){ //C+
										reg[i].ggpa = 2.50;
										fprintf(test_gpa,"Grade: C+ \n");
									}
									if(input_grade[i] == 5){ //C
										reg[i].ggpa = 2.00;
										fprintf(test_gpa,"Grade: C \n");
									}
									if(input_grade[i] == 6){ //D+
										reg[i].ggpa = 1.50;
										fprintf(test_gpa,"Grade: D+ \n");
									}
									if(input_grade[i] == 7){ //D
										reg[i].ggpa = 1.00;
										fprintf(test_gpa,"Grade: D \n");
									}
									if(input_grade[i] == 8){ //F
										reg[i].ggpa = 0;
										fprintf(test_gpa,"Grade: F \n");
									}
								}else{
									printf("--> ERROR : Input Grade Only 1-17!!!! ");
									duk++;
									break;
								}
								printf("_______________________________________________________________\n\n");
								fprintf(test_gpa,"------------------------------------------------\n");
								}
								if(duk == 1){
								/* ++++++++++++ Process ++++++++++++ */ 
								for(i=0;i<amount_code;i++){
									sum_grade[i] = reg[i].credit * reg[i].ggpa;
								}
								for(i=0;i<amount_code;i++){
									sum_credit += reg[i].credit;
									sum_gpa += sum_grade[i];
								}
								ans = sum_gpa/sum_credit;
								fprintf(test_gpa," C.Register: %d\n",amount_code);
								fprintf(test_gpa," C.Earn: %d\n",amount_code);
								fprintf(test_gpa," CA: %d\n",sum_credit);
								fprintf(test_gpa," GP: %0.0f\n",sum_gpa);
								fprintf(test_gpa," GPA: %0.2f\n",ans);
								fprintf(test_gpa,"-------------------------------------------------\n");
								fclose(test_gpa);
								/* ++++++++++++++++++++++++++++++++ */ 
								printf("\n+++++++++++++++++ Result Grade +++++++++++++++++\n");
								show_sumgpa();
								
								FILE*saveuser;
								time_t rawtime3;
 								time (&rawtime3);
								saveuser = fopen("date/date_testgpa.txt","a");
 								fprintf(saveuser,"ID : %s | ",check_id);
 								fprintf(saveuser,"GPA : %0.2f \n",ans);
    							fprintf(saveuser,"Date Login : %s",ctime(&rawtime3));
    							fprintf(saveuser,"---------------------------------------\n");
    							fclose(saveuser);
								}	
						}
						}while(menu_n != 0);
						}
					}// while
					if(checkww == 0){
    						printf("---> ID Nisit is False. \n");
					}
						
					break;
				
			case 3: /* Login Admin */
					login_admins();
					char admin[20];
					char admins[20];
					int checka = 0;
					printf("Input ID Admin : ");
					scanf("%s",&admins);
    				login_admin = fopen("admin_login.txt", "r");
   					while(fscanf(login_admin, "%s", admin) != EOF){
    					if((strcmp(admins, admin) == 0)){
    						time_t rawtime;
 							time (&rawtime);
    						printf("---> ID Admin is True. : %s \n",ctime(&rawtime));
    						checka++;
    						int choice_menu_admin;
    						do{
    						main_admin();
    						printf("\nPlease Choose Menu : ");
							scanf("%d",&choice_menu_admin);
    						/* List of students */
							if(choice_menu_admin == 1){
								list_idnisit();
							}
							
							if(choice_menu_admin == 2){
								clear_view();
							}
							
							if(choice_menu_admin == 3){
								reg_date();
							}
							
							if(choice_menu_admin == 4){
								login_date();
							}
								
							if(choice_menu_admin == 5){
								usertest_gpa();
							}	
    						}while(choice_menu_admin != 0);
						}
					}
					if(checka == 0){
    					printf("---> ID Nist is False. \n");
					}			
			break;			
		}//switch
	}while(choice !=0);//do
}//main

int register_nisit(void){
	/* ++++++++++ Faculty ++++++++++ */
	char fpacu1[99] = "Faculty Of Engineering";
	char fpacu2[99] = "Faculty Of Humanities and Social Sciences";
	char fpacu3[99] = "Faculty Of Management and Tourism";
	char fpacu4[99] = "Faculty Of Nursing";
	char fpacu5[99] = "Faculty Of Geoinformatics";
	char fpacu6[99] = "Faculty Of Political Science and Law";
	char fpacu7[99] = "Faculty Of Abhaibhubej Thai Traditional Medicine";
	char fpacu8[99] = "Faculty Of Medicine";
	char fpacu9[99] = "Faculty Of Pharmaceutical Sciences";
	char fpacu10[99] = "Faculty Of Music and Performing Arts";
	char fpacu11[99] = "Faculty Of Logistics";
	char fpacu12[99] = "Faculty Of Informatics";
	char fpacu13[99] = "Faculty Of Sciences";
	char fpacu14[99] = "Faculty Of Education";
	char fpacu15[99] = "Faculty Of Fine and Applied Arts";
	char fpacu16[99] = "Faculty Of Sport Sciences ";
	char fpacu17[99] = "Faculty Of Allied Health Sciences";
	int amount_reg,i,input_facu;
	struct DATA nisit[9999];
	FILE*regnisit;
	FILE*login_id;
	FILE*date_reg;
	regnisit = fopen("data_nisit.txt","a");
	login_id = fopen("id_login.txt","a");
	date_reg = fopen("date/date_reg.txt","a");
	printf("\n\n_________________________________________");
	printf("\n\n ++++++++++++++ Register ++++++++++++++");
	printf("\n_________________________________________\n");
	printf("Input Amount : ");
	scanf("%d",&amount_reg);
	for(i=0;i<amount_reg;i++){
		printf("\n[%d]Input ID Nist    : ",i+1);
		scanf("%8s",&nisit[i].id);
		fprintf(regnisit,"ID: %s | ",nisit[i].id);
		fprintf(login_id,"ID: %s  \n",nisit[i].id);
		fprintf(date_reg," ID: %s  \n",nisit[i].id);
		printf("   Input First Name : ");
		scanf("%s",&nisit[i].nname);
		fprintf(regnisit,"Name: %s ",nisit[i].nname);
		printf("   Input Last Name  : ");
		scanf("%s",&nisit[i].lname);
		fprintf(regnisit,"%s | ",nisit[i].lname);
		printf("   Input Age        : ");
		scanf("%d",&nisit[i].age);
		fprintf(regnisit,"Age: %d | ",nisit[i].age);
		faculty_view();
		printf("\n   Input Faculty    : ");
		scanf("%d",&input_facu);
		if(input_facu <= 17 && input_facu >= 1){
		if(input_facu == 1){
			fprintf(regnisit,"Faculty: %s \n",fpacu1);
		}
		if(input_facu == 2){
			fprintf(regnisit,"Faculty: %s \n",fpacu2);
		}
		if(input_facu == 3){
			fprintf(regnisit,"Faculty: %s \n",fpacu3);
		}
		if(input_facu == 4){
			fprintf(regnisit,"Faculty: %s \n",fpacu4);
		}
		if(input_facu == 5){
			fprintf(regnisit,"Faculty: %s \n",fpacu5);
		}
		if(input_facu == 6){
			fprintf(regnisit,"Faculty: %s \n",fpacu6);
		}
		if(input_facu == 7){
			fprintf(regnisit,"Faculty: %s \n",fpacu7);
		}
		if(input_facu == 8){
			fprintf(regnisit,"Faculty: %s \n",fpacu8);
		}
		if(input_facu == 9){
			fprintf(regnisit,"Faculty: %s \n",fpacu9);
		}
		if(input_facu == 10){
			fprintf(regnisit,"Faculty: %s \n",fpacu10);
		}
		if(input_facu == 11){
			fprintf(regnisit,"Faculty: %s \n",fpacu11);
		}
		if(input_facu == 12){
			fprintf(regnisit,"Faculty: %s \n",fpacu12);
		}
		if(input_facu == 13){
			fprintf(regnisit,"Faculty: %s \n",fpacu13);
		}
		if(input_facu == 14){
			fprintf(regnisit,"Faculty: %s \n",fpacu14);
		}
		if(input_facu == 15){
			fprintf(regnisit,"Faculty: %s \n",fpacu15);
		}
		if(input_facu == 16){
			fprintf(regnisit,"Faculty: %s \n",fpacu16);
		}
		if(input_facu == 17){
			fprintf(regnisit,"Faculty: %s \n",fpacu17);
		}
		}else{
			printf("--> ERROR : Input Faculty Only 1-17!!!! ");
			return 0;
		}
		time_t rawtime;
 		time (&rawtime);
 		fprintf(date_reg," Date: %s ",ctime(&rawtime));
 		fprintf(date_reg,"-----------------------------------\n");
	}
	if(i = amount_reg){
		fclose(regnisit);
		fclose(login_id);	
		fclose(date_reg);
		time_t rawtime;
 		time (&rawtime);
 		total_reg();
		printf("\n---> You Register Complete : %s",ctime(&rawtime));
	}
}

void clear_data(void){
	FILE*deldata;
	FILE*delid;
	FILE*deldatereg;
	FILE*datelogin;
	FILE*viewusertestgpa;
	FILE*deltotalreg;
	
	delid = fopen("id_login.txt","w");
	deldata = fopen("data_nisit.txt","w");
	deldatereg = fopen("date/date_reg.txt","w");
	datelogin = fopen("date/date_login.txt","w");
	viewusertestgpa = fopen("date/date_testgpa.txt","w");
	deltotalreg = fopen("amount/total_register.txt","w");
	
	char del[40] = "";
	fprintf(deldata,"%s\n",del);
	fprintf(delid,"%s\n",del);
	fprintf(deldatereg,"%s\n",del);
	fprintf(datelogin,"%s\n",del);
	fprintf(viewusertestgpa,"%s\n",del);
	fprintf(deltotalreg,"0\n");
	
	fclose(delid);
	fclose(deldata);
	fclose(deldatereg);
	fclose(datelogin);
	fclose(viewusertestgpa);
	fclose(deltotalreg);
	time_t rawtime;
 	time (&rawtime);
 	printf("\n---> Clear Data : Completed. : %s \n",ctime(&rawtime));
}

void reg_date(void){
	printf("\n\n_________________________________________");
	printf("\n\n ++++++++ View Registration Date ++++++++");
	printf("\n_________________________________________\n");
	FILE * regdate2;
 	int reg_date2;
 	char txt_reg2;
 	regdate2 = fopen("date/date_reg.txt","r");
	reg_date2 = fscanf(regdate2,"%c",&txt_reg2);
	while(reg_date2 != EOF)
 	{
 		fprintf(stdout,"%c",txt_reg2);
		reg_date2 = fscanf(regdate2,"%c",&txt_reg2);
 	}
 		fclose(regdate2);
 		printf("\n\n");
	
}

void login_date(void){
	printf("\n\n_________________________________________");
	printf("\n\n ++++++++++++ View Login Date ++++++++++++");
	printf("\n_________________________________________\n");
	FILE * logdate2;
 	int log_date2;
 	char txt_log2;
 	logdate2 = fopen("date/date_login.txt","r");
	log_date2 = fscanf(logdate2,"%c",&txt_log2);
	while(log_date2 != EOF)
 	{
 		fprintf(stdout,"%c",txt_log2);
		log_date2 = fscanf(logdate2,"%c",&txt_log2);
 	}
 		fclose(logdate2);
 		printf("\n\n");
}

void show_sumgpa(void){
	FILE * sumgpa;
 	int sum_gpa;
 	char txt_sumgpa;
 	sumgpa = fopen("test_grade.txt","r");
	sum_gpa = fscanf(sumgpa,"%c",&txt_sumgpa);
	while(sum_gpa != EOF)
 	{
 		fprintf(stdout,"%c",txt_sumgpa);
		sum_gpa = fscanf(sumgpa,"%c",&txt_sumgpa);
 	}
 		fclose(sumgpa);
 		printf("\n\n");
}

void list_idnisit(void){
	printf("\n\n_________________________________________");
	printf("\n\n ++++++++++ List of students ++++++++++");
	printf("\n_________________________________________\n");
	printf("Total Register : ");
	view_total_reg();
	FILE*list_id;
	int listid;
 	char txt_id;
 	list_id = fopen("data_nisit.txt","r");
	listid = fscanf(list_id,"%c",&txt_id);
	while(listid != EOF)
 	{
 		fprintf(stdout,"%c",txt_id);
		listid = fscanf(list_id,"%c",&txt_id);
	}
 	fclose(list_id);
 	printf("\n\n");
}

void usertest_gpa(void){
	printf("\n\n_________________________________________");
	printf("\n\n +++++ List of User Test Grade +++++");
	printf("\n_________________________________________\n");
	FILE*usertest;
	int ut;
 	char txt_tt;
 	usertest = fopen("date/date_testgpa.txt","r");
	ut = fscanf(usertest,"%c",&txt_tt);
	while(ut != EOF)
 	{
 		fprintf(stdout,"%c",txt_tt);
		ut = fscanf(usertest,"%c",&txt_tt);
	}
 	fclose(usertest);
 	printf("\n\n");
}

void view_total_reg(void){
	FILE*showtotal_reg;
	int vtr;
 	char txt_ttr;
 	showtotal_reg = fopen("amount/total_register.txt","r");
	vtr = fscanf(showtotal_reg,"%c",&txt_ttr);
	while(vtr != EOF)
 	{
 		fprintf(stdout,"%c",txt_ttr);
		vtr = fscanf(showtotal_reg,"%c",&txt_ttr);
	}
 	fclose(showtotal_reg);
 	printf("\n");
}


void profile_view(void){
	printf("\n\n_________________________________________");
	printf("\n\n ++++++++++++ Nisit Manager ++++++++++++");
	printf("\n_________________________________________\n");
	printf("\n\t1. Grade test");
	printf("\n\n\t0.Back");
	printf("\n_________________________________________\n");
}

void main_menu(void){
	printf("\n\n_____________________________________________");
	printf("\n\n ++++++++++++++ Main Menu ++++++++++++++");
	printf("\n_____________________________________________\n");
	printf("\n\t1.Register Nisit\n");
	printf("\n\t2.Login Nisit \n");
	printf("\n\t3.Login Admin \n");
	printf("\n\t0.Exit");
	printf("\n_________________________________________\n");
}

void faculty_view(void){
	printf("_____________________________________________________\n\n");
	printf("\t\t Example Faculty");
	printf("\n_____________________________________________________\n\n");
	printf("\t   1) Faculty Of Engineering \n");
	printf("\t   2) Faculty Of Humanities and Social Sciences \n");
	printf("\t   3) Faculty Of Management and Tourism \n");
	printf("\t   4) Faculty Of Nursing \n");
	printf("\t   5) Faculty Of Geoinformatics \n");
	printf("\t   6) Faculty Of Political Science and Law \n");
	printf("\t   7) Faculty Of Abhaibhubej Thai Traditional Medicine \n");
	printf("\t   8) Faculty Of Medicine \n");
	printf("\t   9) Faculty Of Pharmaceutical Sciences \n");
	printf("\t  10) Faculty Of Music and Performing Arts \n");
	printf("\t  11) Faculty Of Logistics \n");
	printf("\t  12) Faculty Of Informatics \n");
	printf("\t  13) Faculty Of Sciences \n");
	printf("\t  14) Faculty Of Education \n");
	printf("\t  15) Faculty Of Fine and Applied Arts \n");
	printf("\t  16) Faculty Of Sport Sciences \n");
	printf("\t  17) Faculty Of Allied Health Sciences \n");
}

void login(void){
	printf("\n___________________________________________\n\n");
	printf(" +++++++++++++ Login Nisit +++++++++++++");
	printf("\n___________________________________________\n\n");
	printf("Please Input ID Nisit : ");
}

void login_admins(void){
	printf("\n___________________________________________\n\n");
	printf(" +++++++++++++ Login Admin +++++++++++++");
	printf("\n___________________________________________\n\n");
}

void ex_code(void){
	printf("_______________________________________________________________\n\n");
	printf("\t\t Example Input Registration Code\n");
	printf("_______________________________________________________________\n\n");
	printf("\t85111059 (Exercise for Quality of Life) ---> 1 Credit \n");
	printf("\t99910259 (Collegiate English)           ---> 3 Credit \n");
	printf("\t88510059 (Logical Thinking)             ---> 2 Credit \n");
	printf("_______________________________________________________________\n");
}

void gpa(void){
	printf("\n\n_________________________________________");
	printf("\n\n ++++++++++ Input GRADE ++++++++++");
	printf("\n_________________________________________\n");
}

void main_admin(void){
	printf("\n\n_________________________________________");
	printf("\n\n +++++++++++ ADMIN Manager +++++++++++");
	printf("\n_________________________________________\n");
	printf("\n\t1. List of all students");
	printf("\n\t2. Clear Data Nisit");
	printf("\n\t3. View Registration Date");
	printf("\n\t4. View Login Date");
	printf("\n\t5. View User Test Grade");
	printf("\n\n\t0.Back");
	printf("\n_________________________________________\n");
}

void clear_view(void){
	/* clear */
	int cl;
	printf("\n----------------------------------------");
	printf("\nYou want to clear Data");
	printf("\n1. Yes");            
	printf("\n2. No");
	printf("\n----------------------------------------");
	printf("\nPlease Choose Menu : ");
	scanf("%d",&cl);
		if(cl <= 2 && cl >= 1){
         	if(cl == 1){
           		clear_data();
			}else{
				return ;
			}
		}
}

void view_gpa(void){
	printf("_______________________________________________________________\n");
	printf("\n\t1) Grade : A  = 4.00 ");
	printf("\n\t2) Grade : B+ = 3.50");
	printf("\n\t3) Grade : B  = 3.00 ");
	printf("\n\t4) Grade : C+ = 2.50 ");
	printf("\n\t5) Grade : C  = 2.00 ");
	printf("\n\t6) Grade : D+ = 1.50 ");
	printf("\n\t7) Grade : D  = 1.00 ");
	printf("\n\t8) Grade : F  = 0 \n");
}

void total_user(void){
	char tup[10];
	FILE *sa;
    sa = fopen("amount/total_userprogram.txt", "r");
    while(fscanf(sa, "%s", tup) != EOF){		
	}
	int num = 0;
	num++;
	printf("\n---> Total number of users = %d",num);
	sa = fopen("amount/total_userprogram.txt", "w");
    fprintf(sa,"%d",num);
    fclose(sa);
}

void total_reg(void){
	char ttr[10];
	FILE*total_r;
    total_r = fopen("amount/total_register.txt", "r");
    while(fscanf(total_r, "%s", ttr) != EOF){		
	}
	int ttr1 = 0;
	ttr1++;
	total_r = fopen("amount/total_register.txt", "w");
    fprintf(total_r,"%d",ttr1);
    fclose(total_r);
}
