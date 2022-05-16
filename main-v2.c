#include <stdio.h>
#include<string.h>
#define MAX 256
int
main ()
{
  FILE *pFile;
  char name[256], size[256], serve[256], simpan, c;

  int n = 0, i, pjname = 0, pjsize = 0, pjserve = 0, price, value, pilihmenu;

  do
    {
      printf ("============================\n");
      printf ("     TRANSAKSI TOKO    \n");
      printf ("============================\n");
      printf ("PILIHAN MENU\n");
      printf ("[1].Input data \n");
      printf ("[2].View History \n");
      printf ("[3].Delete History \n");
      printf ("[4].Exit \n");
      printf ("Masukkan pilihan anda [1 - 4] : ");
      scanf ("%d", &pilihmenu);

      if (pilihmenu == 1)
	{
	  do
	    {
	      printf ("Nama Minuman : ");
	      scanf ("%s", name);
	      //Count name character
	      for (i = 0; i[name] != '\0'; i++)
		{
		  if (name[i] != ' ');
		  {
		    pjname++;
		  }
		}
	      //to NAME TO UPPERCASE
	      for (i = 0; name[i] != '\0'; i++)
		{
		  if (name[i] >= 'a' && name[i] <= 'z')
		    {
		      name[i] = name[i] - 32;
		    }
		}

	      if (strcmp (name, "KOPI") == 0 || strcmp (name, "TEH") == 0
		  || strcmp (name, "COKELAT") == 0
		  || strcmp (name, "SODA") == 0)
		{
		  value = 0;
		}
	      else
		{
		  value = 1;
		  printf ("Nama minuman tidak ditemukan ! \n");
		  printf
		    ("Masukkan nama yang diizinkan : KOPI, TEH, COKELAT DAN SODA \n");
		}

	    }
	  while (value == 1);

	  do
	    {
	      printf ("Size : ");
	      scanf ("%s", size);
	      //Count size character
	      for (i = 0; i[size] != '\0'; i++)
		{
		  if (size[i] != ' ');
		  {
		    pjsize++;
		  }
		}
	      //to SIZE TO UPPERCASE
	      for (i = 0; size[i] != '\0'; i++)
		{
		  if (size[i] >= 'a' && size[i] <= 'z')
		    {
		      size[i] = size[i] - 32;
		    }
		}

	      if (strcmp (size, "SMALL") == 0 || strcmp (size, "MEDIUM") == 0
		  || strcmp (size, "LARGEST") == 0)
		{
		  value = 0;
		}
	      else
		{
		  value = 1;
		  printf ("Ukuran tidak ditemukan ! \n");
		  printf
		    ("Masukkan ukuran yang diizinkan : SMALL, MEDIUM, DAN LARGEST \n");
		}

	    }
	  while (value == 1);



	  do
	    {
	      printf ("Penyajian : ");
	      scanf ("%s", serve);
	      //Count serve character
	      for (i = 0; i[serve] != '\0'; i++)
		{
		  if (serve[i] != ' ');
		  {
		    pjserve++;
		  }
		}
	      //to SERVE TO UPPERCASE
	      for (i = 0; serve[i] != '\0'; i++)
		{
		  if (serve[i] >= 'a' && serve[i] <= 'z')
		    {
		      serve[i] = serve[i] - 32;
		    }
		}

	      if (strcmp (serve, "DINGIN") == 0
		  || strcmp (serve, "PANAS") == 0
		  || strcmp (serve, "HANGAT") == 0)
		{
		  value = 0;
		}
	      else
		{
		  value = 1;
		  printf ("Penyajian tidak ditemukan ! \n");
		  printf
		    ("Masukkan penyajian yang diizinkan : DINGIN, PANAS, DAN HANGAT \n");
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

	  printf ("Apakah anda ingin menyimpan transaksi ini ? (y/n) : ");
	  scanf ("%s", &simpan);
	  if (simpan == 'y' || simpan == 'Y')
	    {

	      pFile = fopen ("dataminuman.txt", "a");
	      fprintf (pFile, "%s %s %s %s %s %s %d %s", name, ",", size, ",",
		       serve, ",", price, "\n");
	      fclose (pFile);
	      printf ("TRANSAKSI TELAH DISIMPAN  \n");
	      printf ("TERIMA KASIH ;) \n");
	      
	      return 0;
	    }
	  else
	    {
	      pilihmenu != 4;
	    }



	}
      else if (pilihmenu == 2)
	{
	  pFile = fopen ("dataminuman.txt", "r");
	  printf ("================================ : \n");
	  printf ("DATA HISTORY TRANSAKSI : \n");
	  printf ("================================ : \n");
	  do
	    {
	      c = fgetc (pFile);
	      printf ("%c", c);
	    }
	  while (c != EOF);
	  fclose (pFile);
	  printf ("\n");
	  pilihmenu != 4;

	}
      else if (pilihmenu == 3)
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
                return 0;
        }
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Temporari file tidak bisa diedit!!\n");
                fclose(fptr1);
                return 0;
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

	}



    }
  while (pilihmenu != 4);

  printf ("TERIMA KASIH !");
  return 0;
}
