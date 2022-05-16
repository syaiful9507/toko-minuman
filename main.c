#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void menu1();
void menu2();
void menu3();
void back();

int returnmenu;

FILE *pFile;

int main()
{
    FILE *sourcefile;
    char listminuman;
    int menu;
    
    sourcefile = fopen("listminuman.txt","r");
    
    puts("");
    puts ("============================");
    puts ("     TRANSAKSI MINUMAN    ");
    puts ("============================");
    
    puts ("List Minuman");
    if (NULL == sourcefile){
        printf("File tidak ditemukan.");
    }
    
    else {
        do {
            printf("%c", listminuman);
        }
        while ((listminuman = getc(sourcefile)) != EOF);
        fclose(sourcefile);
    }
    printf("\n");
    printf ("\nPilihan Menu:\n");
    puts("1. Input data");
    puts("2. View History");
    puts("3. Delete History");
    puts("4. Exit");
    printf("Silakan pilih : "); scanf("%d",&menu);
    //printf("Silakan pilih : "); scanf("%c",&menu);
    
    switch(menu)
	{
		case 1:
			menu1();
			break;
		case 2:
			menu2();
			break;
		case 3:
			menu3();
			break;
		case 4:
		printf("Terima kasih atas kunjungan Anda.");
			exit(1);
			//break;
	}
    
    /*
    if (menu == '1') {
        printf("Program Exit");
    }
    else if (menu == '2') {
        
    }
    else {
        printf("Program Exit");
    }
    */
    //return (0);
}

void menu1()
{
    char name[10],size[10],serve[10], simpan;
    int i, value, price, pjname = 0, pjsize = 0, pjserve = 0;
    
    do {
        printf ("Nama Minuman : "); scanf ("%s", name);
	    //Count name character
	    for (i = 0; i[name] != '\0'; i++) {
	        if (name[i] != ' ') {
		    pjname++;
	        }
	    }
	    
	    //to NAME TO UPPERCASE
	    for (i = 0; name[i] != '\0'; i++) {
	        if (name[i] >= 'a' && name[i] <= 'z') {
	            name[i] = name[i] - 32;
	            
	        }
	    }
	    
	    if (strcmp (name, "KOPI") == 0 || strcmp (name, "TEH") == 0
		  || strcmp (name, "COKELAT") == 0
		  || strcmp (name, "SODA") == 0)
		{
		  value = 0;
		}
		
	    else {
	        value = 1;
	        printf ("Nama minuman tidak ditemukan ! \n");
	        printf ("Masukkan nama yang diizinkan : KOPI, TEH, COKELAT DAN SODA \n");
		}
    }
	while (value == 1);
	
	do {
	    printf ("Size : ");
	    scanf ("%s", size);
	    
	    //Count size character
	    for (i = 0; i[size] != '\0'; i++) {
	        if (size[i] != ' ') {
	            pjsize++;
	        }
		}
		//to SIZE TO UPPERCASE
	    for (i = 0; size[i] != '\0'; i++) {
	        if (size[i] >= 'a' && size[i] <= 'z') {
	            size[i] = size[i] - 32;
		    }
		}
		
		if (strcmp (size, "SMALL") == 0 || strcmp (size, "MEDIUM") == 0 || strcmp (size, "LARGEST") == 0) {
		    value = 0;
		}
		
		else {
		    value = 1;
		    printf ("Ukuran tidak ditemukan ! \n");
		    printf ("Masukkan ukuran yang diizinkan : SMALL, MEDIUM, DAN LARGEST \n");
		}
	}
	while (value == 1);

	do {
	    printf ("Penyajian : "); scanf ("%s", serve);
	    
	    //Count serve character
	    for (i = 0; i[serve] != '\0'; i++) {
	        if (serve[i] != ' ') {
	            pjserve++;
	        }
		}
	    //to SERVE TO UPPERCASE
	    for (i = 0; serve[i] != '\0'; i++) {
		    if (serve[i] >= 'a' && serve[i] <= 'z') {
		        serve[i] = serve[i] - 32;
		    }
		}
		
		if (strcmp (serve, "DINGIN") == 0 || strcmp (serve, "PANAS") == 0 || strcmp (serve, "HANGAT") == 0) {
		    value = 0;
		}
		
	    else { 
	        value = 1;
	        printf ("Penyajian tidak ditemukan ! \n");
		    printf ("Masukkan penyajian yang diizinkan : DINGIN, PANAS, DAN HANGAT \n");
	    }
	    
	}
	while (value == 1);
	
	price = pjsize * pjname * pjserve * 100;
	printf ("===============================\n");
	printf ("        DATA PESANAN     \n");
	printf ("===============================\n");
	printf ("Nama Minuman : %s \n", name);
	printf ("Size         : %s \n", size);
	printf ("Penyajian    : %s \n", serve);
	printf ("Harga        : %d \n", price);
	printf ("===============================\n");
	printf ("Apakah anda ingin menyimpan transaksi ini ? (y/n) : "); scanf ("%s", &simpan);
	if (simpan == 'y' || simpan == 'Y') {
	    pFile = fopen ("dataminuman.txt", "a");
	    fprintf (pFile, "%s %s %s %s %s %s %d %s", name, ",", size, ",", serve, ",", price, "\n");
		fclose (pFile);
		printf ("TRANSAKSI TELAH DISIMPAN\n");
		printf("\n");
	}
	
	else {
	    printf("\n");
	}
	
	printf("Kembali ke menu? 0 (kembali) : "); scanf("%d",&returnmenu);
	switch(returnmenu)
	default:
		back();
	
	//printf("Input nama minuman: "); scanf("%s",name);
	//printf("Input ukuran: "); scanf("%s",size);
	//printf("Input penyajian: "); scanf("%s",serve);
	//puts("Nama: %s, ukuran: %s, penyajian: %s");
	//printf("Apakah ingin kembali ke menu? y/n : "); scanf("%d",&returnmenu);
	switch(returnmenu)
	default:
		back();
}

void menu2()
{
    char c;
    pFile = fopen ("dataminuman.txt", "r");
	printf ("================================ : \n");
	printf ("DATA HISTORY TRANSAKSI : \n");
	printf ("================================ : \n");
	
	do {
	    c = fgetc (pFile);
	    printf ("%c", c);
	}
	
	while (c != EOF);
	fclose (pFile);
	printf ("\n");
	printf("Apakah ingin kembali ke menu? 0 (kembali) : "); scanf("%d",&returnmenu);
	switch(returnmenu)
	default:
		back();
}

void menu3()
{
	int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
        char str[MAX], temp[] = "temp.txt";
		char fname[] = "dataminuman.txt";	
        fptr1 = fopen(fname, "r");
        if (!fptr1) 
		{
                printf(" File Tidak Ditemukan\n");
        }
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Temporari file tidak bisa diedit!!\n");
                fclose(fptr1);
        }
        printf(" Baris yang akan di hapus : ");
        scanf("%d", &lno);
		lno;
        
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
               
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);  		
        rename(temp, fname); 

  		 fptr1=fopen(fname,"r"); 
            ch=fgetc(fptr1); 
        printf ("================================ : \n");
		printf ("DATA HISTORY TRANSAKSI : \n");
		printf ("================================ : \n");
          while(ch!=EOF) 
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }
        fclose(fptr1);
	printf("Apakah ingin kembali ke menu? 0 (kembali) : "); scanf("%d",&returnmenu);
	switch(returnmenu)
	default:
		back();
}

void back()
{
	if (returnmenu == 0) {
	    printf("\n");
		switch(returnmenu)
			default:
			main();
	}
	
	else {
	    printf("Terima kasih atas kunjungan Anda.");
	    exit(1);
	}
}
