// Name : Kesha Shah
// Id : 201101228

// Coding Theory - Decoding with a binary Hamming Code.
#include<stdio.h>
#include<math.h>

int main()
{
	// n -> length of codeword
	// k -> basis dimension
	// d -> minimum distance
	// r -> a positive integer >=2
	// q -> qary code
	int n,k,d,r,q; 
	char d_cont,h_cont;
	int new_Hamming=1, new_code=1;

	while(new_Hamming)
	{
		//getting values 
		printf("Enter r:");
		scanf("%d",&r);
		n=((int)pow(2,r))-1;
		k=n-r;
		
		int i,j; //to go over rows and cols
		
		int Hmat[r][n]; // the H matrix
		
		// Getting H matrix
		printf("Enter H matrix row-wise below.\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("Enter H[%d][%d]: ",i+1,j+1);
				scanf("%d",&Hmat[i][j]);
			}	
		}

		// Getting the codeword
		int codeword[n];
		while(new_code)
		{
		for(i=0;i<n;i++)
		{
			printf("Enter codeword[%d]: ",i+1);
			scanf("%d",&codeword[i]);
		}

//		printf("Debug 1");
		// computing the answer
		int syndrome[r];

		printf("Your codeword has syndrome: ");		
		for(i=0;i<r;i++)
		{
			syndrome[i]=0;
			for(j=0;j<n;j++)
			{
				if(codeword[j]==1)
					syndrome[i] += Hmat[i][j];
			}
			syndrome[i]%=2;
			printf("%d",syndrome[i]);
		}

//		printf("Debug 2");
		// getting the error bit from syndrome
		int errorbit = 0;
		for(i=r-1;i>=0;i--)
		{
			if(syndrome[i] == 1)
			{
				errorbit += pow(2,r-1-i); 
			}
		}

//		printf("Debug 3");
		if(errorbit ==0 )
			printf("\nNo error occured\n");
		else
			printf("\nError occured at %d bit\n",errorbit);
		
		errorbit -= 1; //because C index starts with 0

		//correcting the error
		codeword[errorbit] = 1 - codeword[errorbit];
		
		printf("Actual code word is: ");
		for(i=0;i<n;i++)
		{
			printf("%d ",codeword[i]);
		}

		//getting the wish to decode another codeword
		printf("\nDo you wish to have new codeword?(y/n)");	
		scanf("%c",&d_cont);
		while(d_cont != 'y' && d_cont != 'n')
		{
			printf("\nEnter y or n:");
			scanf("%c",&d_cont);
		}
		if(d_cont == 'n')
			new_code = 0;
		else
			new_code = 1;
		}

	// getting the wish to check next Hamming code and error in codeword
		printf("\nDo you want to have new Hamming code?(y/n): ");
		scanf("%c",&h_cont);
		while(h_cont != 'y' && h_cont != 'n')
		{
			printf("\nEnter y or n: ");
			scanf("%c",&h_cont);
		}
		
		if(h_cont == 'n')
			new_Hamming = 0;
		else
			new_Hamming = 1;
	}

	return 0;
}
