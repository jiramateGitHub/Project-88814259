void total_user(void){
	char tup[10];
	FILE *sa;
    sa = fopen("amount/total_userprogram.txt", "r");
    while(fscanf(sa, "%s", tup) != EOF){		
	}
	int num = atoi(tup);
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
	int ttr1 = atoi(ttr);
	ttr1++;
	total_r = fopen("amount/total_register.txt", "w");
    fprintf(total_r,"%d",ttr1);
    fclose(total_r);
}
