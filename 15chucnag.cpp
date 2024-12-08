
#include<stdio.h>

int main(){
	int arr[100];
	int size = 0, choice;
	int sx = 0;
	do{
		printf("\n\n\tMENU\n");
		printf("\n1. Nhap vao so phan tu va gia tri cho mang.\n");
		printf("2. In ra cac phan tu trong mang.\n");
		printf("3. Tim so luong so hoan hao.\n");
		printf("4. Tim so luong so nguyen to.\n");
		printf("5. In ra phan tu lon thu 2 cua mang.\n");
		printf("6. In ra phan tu nho thu 2 cua mang.\n");
		printf("7. Them vao phan tu moi.\n");
		printf("8. Xoa phan tu.\n");
		printf("9. Sap xep mang theo thu tu tang dan.\n");
		printf("10. Sap xep mang theo thu tu giam dan.\n");
		printf("11. Tim kiem phan tu.\n");
		printf("12. Xoa phan tu trung lap, in ra cac phan tu doc nhat.\n");
		printf("13. Sap xep dua so le len truoc so chan xuong cuoi mang va in ra.\n");
		printf("14. Dao nguoc phan tu trong mang.\n");
		printf("15. Thoat\n");
		printf("\nNhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Nhap vao kich thuoc cua mang: ");
				scanf("%d", &size);
				if(size > 0){
					for(int i = 0; i < size; i++){
						printf("Nhap vao phan tu thu %d cua mang: ", i + 1);
						scanf("%d", &arr[i]);
					}
				}else{
					printf("kich thuoc mang khong hop le");
				}
				break;
			case 2:
				if(size > 0){
					for(int i = 0; i < size; i++){
						printf("arr[%d] = %d\n", i, arr[i]);
					}
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 3:
				if(size > 0){
					int dem = 0;
					for(int i = 0; i < size; i++){
						int sum = 0;
						int n = arr[i];
						for(int j = 1; j < n;j++){
							if(n % j ==0){
								sum += j;
							}
						}
						if(n == sum){
							dem++;
						}
					}
					printf("so luong so hoan hao trong mang la: %d\n", dem);
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 4:
				if(size > 0){
					int dem = 0;
					for(int i = 0; i < size; i++){
						int snt =arr[i];
						int check = 1; 
						if(arr[i] < 2){
							check = 0; 
						}else{
							for(int j =2; j <= snt/2;j++){
								if(snt % j == 0){
									check =0; 
								} 
							}
							if(check){
								dem++;
							}
						}
					}
					printf("so luong so nguyen to trong mang la: %d\n", dem);
				}else{
					printf("chua khoi tao mang");
				}
				break;	
			case 5:
				if(size > 0){
					int max = arr[0];
					int max2 = arr[size - 1];
					for(int i = 1; i < size; i++){
						if(max < arr[i]){
							max = arr[i];
						}
					}
					for(int i = 0; i < size; i++){
						if(max2 < arr[i]&&arr[i] < max){
							max2 = arr[i];
						}
					}
					printf("Phan tu lon thu 2 cua mang la: %d", max2);
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 6:
				if(size > 0){
					int min = arr[0];
					int min2 = arr[size - 1];
					for(int i = 1; i < size; i++){
						if(min > arr[i]){
							min = arr[i];
						}
					}
					for(int i = 0; i < size; i++){
						if(min2 > arr[i]&&arr[i] > min){
							min2 = arr[i];
						}
					}
					printf("Phan tu nho thu 2 cua mang la: %d", min2);
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 7:
				if(size > 0){
					int viTri, phanTu;
					printf("Nhap vao vi tri muon them: ");
					scanf("%d", &viTri);
					if(viTri < 0|| viTri > size){
						printf("vi tri khong hop le\n");
						continue;
					}
					printf("Nhap vao phan tu muon them: ");
					scanf("%d", &phanTu);
					for(int i = size; i > viTri-1; i--){
						arr[i] = arr[i - 1];
					}
					arr[viTri - 1] = phanTu;
					size ++;
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 8:
				if(size > 0){
					int viTri;
					printf("Nhap vao vi tri muon xoa: ");
					scanf("%d", &viTri);
					if(viTri < 0|| viTri > size){
						printf("vi tri khong hop le\n");
						continue;
					}
					for(int i = viTri - 1; i < size; i++){
						arr[i] = arr[i + 1];
					}
					size --;
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 9:
				if(size > 0){
					for(int i =1; i<size; i++){
						int key = arr[i];
						int j;
						for(j=i-1; j>=0&&arr[j]>key; j--){
							arr[j+1]= arr[j];
						}
						arr[j+1]=key;
					}
					sx = 1;
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 10:
				if(size > 0){
					for(int i =1; i<size; i++){
						int key = arr[i];
						int j;
						for(j=i-1; j>=0&&arr[j]<key; j--){
							arr[j+1]= arr[j];
						}
						arr[j+1]=key;
					}
					sx = 1;
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 11:
				if(size > 0){
					if(sx == 1){
						int search;
						int check = 0;
						int left = 0;
	    				int right = size - 1;
						printf("So can tim: ");
						scanf("%d", &search);
						while (left <= right) {
					        int mid = left + (right - left) / 2;
					        if (arr[mid] == search) { 
					        	check =1;
					            break;
					        }
					        if (arr[mid] > search) {
					            right = mid - 1;
					        } 
					        else {
					            left = mid + 1;
					        }
					    }
					    left = 0;
	    				right = size - 1;
					    while (left <= right) {
					        int mid = left + (right - left) / 2;
					        if (arr[mid] == search) { 
					        	check =1;
					            break;
					        }
					        if (arr[mid] > search) {
					        	left = mid + 1;
					        } 
					        else {
					            right = mid - 1;
					        }
					    }
					    if (check != 0) {
					        printf("Phan tu ton tai trong mang\n");
					    } else {
					        printf("Phan tu khong ton tai trong mang\n");
					    }
					}else{
						printf("chua sap xep mang");
					}
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 12:
				if(size > 0){
					int test = 0;
					for(int i = 0; i < size;i++){
						int check = 0;
						int number = arr[i];
						for(int j = 0; j < size; j++){
							if(number == arr[j]){
								check++;
							}							
						}
						if(check != 1){
							test++;
							for(int f =0; f < size; f++){
								if(number == arr[f]){
									arr[f] = 0;
								}
							}			
						}
					}
					for(int i = size - 1; i > 0; i--){
						for(int j = 0; j < i; j++){
							if(arr[j] == 0){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
					}
					size -= test;
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 13:
				if(size > 0){
					for(int i = size - 1; i > 0; i--){
						for(int j = 0; j < i; j++){
							if(arr[j] > arr[j+1]){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
					}
					for(int i = size - 1; i > 0; i--){
						for(int j = 0; j < i; j++){
							if(arr[j]%2!=0){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
					}
					for(int i = size - 1; i > 0; i--){
						for(int j = 0; j < i; j++){
							if(arr[j]%2!=0&&arr[j] > arr[j+1]){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
					}
					
					printf("\nmang sau khi sap xep:\n");
					for(int i = 0; i < size; i++){
						printf("%d ", arr[i]);
					}
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 14:
				if(size > 0){
					int dau = 0;
					int cuoi = size - 1;
					while (dau < cuoi) {
				        int temp = arr[dau];
				        arr[dau] = arr[cuoi];
				        arr[cuoi] = temp;
				        dau++;
				        cuoi--;
				    }
				}else{
					printf("chua khoi tao mang");
				}
				break;
			case 15:
				printf("thoat!");
				break;
			default:
				printf("Lua chon khong hop le!");		
		}
	}while(choice != 15);
	return 0;
}

