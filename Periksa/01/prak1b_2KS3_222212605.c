#include <stdio.h>
 
int main()
{
	int panjang,lebar,luas,keliling;
	printf("Masukkan Panjang : ");scanf("%d", &panjang);
	printf("Masukkan Lebar : ");scanf("%d", &lebar);
    printf("\n");
	
	luas = nilai_luas(panjang,lebar);
	printf("Luas Persegi Panjang Adalah : %d \n" , luas);
    keliling = nilai_keliling(panjang,lebar);
    printf("Keliling Persegi Panjang Adalah : %d \n ", keliling); 
	return 0;
}

	int nilai_luas(int panjang, int lebar)
{
	int Luas;
	Luas = panjang*lebar;
	return Luas;
}

    int nilai_keliling(int panjang, int lebar)
{
    int Keliling;
    Keliling = (2*(panjang+lebar));
    return Keliling;
}