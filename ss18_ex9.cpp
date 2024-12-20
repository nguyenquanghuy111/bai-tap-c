#include <stdio.h>
#include <string.h>

struct Dish {
    int id;
    char Name[100];
    double price;
};

int main() {
    struct Dish menu[100] = {
        {1, "com", 15000},
        {2, "rau xao thit bo", 30000},
        {3, "mi xao", 20000},
        {4, "bun oc", 35000},
        {5, "mi cay", 60000},
    };
    int choice, sothutu = 0, kichthuoc = 5;

    do {
        printf("1: in ra cac phan tu co trong menu:\n");
        printf("2: them phan tu vao vi tri:\n");
        printf("3: sua mot phan tu:\n");
        printf("4: xoa mot phan tu o vi tri:\n");
        printf("5: sap xep cac phan tu tang hoac giam dan:\n");
        printf("6: tim kiem phan tu theo ten nhap vao:\n");
        printf("7: thoat:\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < kichthuoc; i++) {
                printf("sothutu: %d\n", menu[i].id);
                printf("------------\n");
                printf("mon an: %s\n", menu[i].Name);
                printf("------------\n");
                printf("gia ban: %.2lf\n", menu[i].price);
                if (sothutu < menu[i].id) {
                    sothutu = menu[i].id;
                }
            }
            break;

        case 2:
            menu[kichthuoc].id = kichthuoc + 1;
            printf("Nhap ten mon muon them: \n");
            getchar();
            fgets(menu[kichthuoc].Name, sizeof(menu[kichthuoc].Name), stdin);
            menu[kichthuoc].Name[strcspn(menu[kichthuoc].Name, "\n")] = '\0';
            printf("Nhap gia tien: ");
            scanf("%lf", &menu[kichthuoc].price);
            kichthuoc++;
            for (int i = 0; i < kichthuoc; i++) {
                printf("%d. %s: %.2lf\n", menu[i].id, menu[i].Name, menu[i].price);
            }
            break;

        case 3:
            int idThayDoi;
            printf("Nhap vao id muon sua: ");
            scanf("%d", &idThayDoi);
            getchar();
            if (idThayDoi > kichthuoc || idThayDoi <= 0) {
                printf("Khong ton tai id do\n");
                break;
            }
            for (int i = 0; i < kichthuoc; i++) {
                if (idThayDoi == menu[i].id) {
                    printf("Nhap vao mon sua: ");
                    fgets(menu[i].Name, sizeof(menu[i].Name), stdin);
                    menu[i].Name[strcspn(menu[i].Name, "\n")] = '\0';
                    printf("Nhap vao gia tien muon sua: ");
                    scanf("%lf", &menu[i].price);
                }
            }
            printf("Menu sau khi thay doi la:\n");
            for (int i = 0; i < kichthuoc; i++) {
                printf("%d. %s: %.2lf\n", menu[i].id, menu[i].Name, menu[i].price);
            }
            break;

        case 4: {
            int idXoa;
            printf("Nhap  mon an muon xoa: ");
            scanf("%d", &idXoa);

            int found = 0;
            for (int i = 0; i < kichthuoc; i++) {
                if (menu[i].id == idXoa) {
                    found = 1;
                    for (int j = i; j < kichthuoc - 1; j++) {
                        menu[j] = menu[j + 1];
                    }
                    kichthuoc--;
                    break;
                }
            }
            if (!found) {
                printf("Khong tim thay mon an voi id %d\n", idXoa);
            } else {
                printf("Menu sau khi xoa la:\n");
                for (int i = 0; i < kichthuoc; i++) {
                    printf("%d. %s: %.2lf\n", menu[i].id, menu[i].Name, menu[i].price);
                }
            }
            break;
        }

        case 5:
            int sapXep;
            printf("Nhap 1 de sap xep tang dan, 2 de sap xep giam dan: ");
            scanf("%d", &sapXep);

            for (int i = 0; i < kichthuoc - 1; i++) {
                for (int j = 0; j < kichthuoc - i - 1; j++) {
                    if ((sapXep == 1 && menu[j].price > menu[j + 1].price) ||
                        (sapXep == 2 && menu[j].price < menu[j + 1].price)) {
                        struct Dish temp = menu[j];
                        menu[j] = menu[j + 1];
                        menu[j + 1] = temp;
                    }
                }
            }
            printf("Menu sau khi sap xep:\n");
            for (int i = 0; i < kichthuoc; i++) {
                printf("%d. %s: %.2lf\n", menu[i].id, menu[i].Name, menu[i].price);
            }
            break;

        case 6: {
            char searchName[35];
            printf("Nhap ten mon an can tim: ");
            getchar();
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            int found = 0;
            for (int i = 0; i < kichthuoc; i++) {
                if (strcasecmp(menu[i].Name, searchName) == 0) {
                    printf("Tim thay: id: %d, name: %s, price: %.2lf\n", menu[i].id, menu[i].Name, menu[i].price);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Khong tim thay mon an!\n");
            }
            break;
        }

        case 7:
            printf("Ban da thoat\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 7);

    return 0;
}

