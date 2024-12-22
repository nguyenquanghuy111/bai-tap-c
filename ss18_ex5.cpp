#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    char age[3];
    char phoneNumber[15];
} Student;

int main() {
   Student students[50] = {
        {1, "Nguyen Van A", "20", "0123456789"},
        {2, "Nguyen Van  B", "21", "0987654321"},
        {3, "Nguyen Van C", "19", "0345678901"},
        {4, "Nguyen Van D", "22", "0912345678"},
        {5, "Nguyen Van E", "20", "0898765432"}
    };
    int studentCount =5;
    int searchId;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &searchId);
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].id == searchId) {
            found = 1;
            printf("Nhap ten moi: ");
            scanf(" %[^]%*c", students[i].name);
            printf("Nhap tuoi moi: ");
            scanf("%s", students[i].age);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ID = %d\n", searchId);
    }
    printf("\nDanh sach tat ca sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Age: %s, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    return 0;
}

