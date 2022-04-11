#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    int stock;
    int price;
    struct node *next;
};

struct node *addFood(struct node *head)
{
    system("clear");
    struct node *node, *ptr;
    int stok, harga;
    char nama[50];
    int angka, banyak;

    printf("\nBerapa Makanan yang ingin anda Masukkan : ");
    scanf("%d", &banyak);
    for (int i = 0; i < banyak; i++)
    {
        printf("\nData Makanan %d\n", i + 1);
        printf("Nama    : ");
        scanf("\n%[^\n]", nama);
        printf("Stock   : ");
        scanf("%d", &stok);
        printf("Price   : ");
        scanf("%d", &harga);

        node = (struct node *)malloc(sizeof(struct node));
        strcpy(node->name, nama);
        node->stock = stok;
        node->price = harga;

        if (head == NULL)
        {
            node->next = node;
            head = node;
        }
        else
        {
            ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = node;
            node->next = head;
        }
    }
    printf("\nData makanan berhasil ditambahkan.\n");
    char enter;
    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    system("clear");
    return head;
}

struct node *addBeginning(struct node *head)
{
    system("clear");
    struct node *ptr, *newNode;
    char nama[50];
    int banyak, stok, harga;

    printf("\nData makanan yang ingin ditambahkan akan terletak di list teratas\n");
    printf("\nIngin tambahkan berapa makanan diawal list : ");
    scanf("%d", &banyak);
    for (int i = 0; i < banyak; i++)
    {
        printf("\nData Makanan %d\n", i + 1);
        printf("Nama    : ");
        scanf("\n%[^\n]", nama);
        printf("Stock   : ");
        scanf("%d", &stok);
        printf("Price   : ");
        scanf("%d", &harga);

        newNode = (struct node *)malloc(sizeof(struct node));
        strcpy(newNode->name, nama);
        newNode->stock = stok;
        newNode->price = harga;
        if (head == NULL)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            ptr = head;
            newNode->next = ptr;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            head = newNode;
            ptr->next = head;
        }
    }
    printf("\nData makanan berhasil ditambahkan.\n");
    char enter;
    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    system("clear");
    return head;
}

struct node *addEnd(struct node *head)
{
    system("clear");
    struct node *newNode, *ptr, *preptr;
    int banyak, stok, harga;
    char nama[50];
    printf("\nData makanan akan ditambahkan diakhir\n");
    printf("\nBerapa banyak data makanan yang ingin ditambahkan : ");
    scanf("%d", &banyak);
    for (int i = 0; i < banyak; i++)
    {
        printf("\nData Makanan %d\n", i + 1);
        printf("Nama    : ");
        scanf("\n%[^\n]", nama);
        printf("Stock   : ");
        scanf("%d", &stok);
        printf("Price   : ");
        scanf("%d", &harga);

        newNode = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            ptr = head;
            while (ptr->next != head)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            ptr->next = newNode;
            strcpy(newNode->name, nama);
            newNode->stock = stok;
            newNode->price = harga;
            newNode->next = head;
        }
    }
    printf("\nData makanan berhasil ditambahkan.\n");
    char enter;
    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    system("clear");

    return head;
}

struct node *deleteFirst(struct node *head)
{
    system("clear");
    int pilih;
    struct node *ptr;

    printf("\nApakah anda ingin menghapus data di node pertama?\n");
    printf("1. Ya\n");
    printf("2. Tidak\n");
    printf("Pilih : ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        if (head != NULL)
        {
            ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = head->next;
            free(head);
            head = ptr->next;
            printf("\nData pada node pertama berhasil dihapus.\n");
        }
        else
        {
            printf("\nMaaf, belum ada data yang anda masukkan.");
        }
        break;
    case 2:
        break;

    default:
        break;
    }
    char enter;
    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    system("clear");

    return head;
}

struct node *deleteLast(struct node *head)
{
    system("clear");
    int pilih;
    struct node *ptr, *preptr;
    printf("\nApakah anda ingin menghapus data di node terakhir?\n");
    printf("1. Ya\n");
    printf("2. Tidak\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        if (head != NULL)
        {
            ptr = head;
            while (ptr->next != head)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = head;
            free(ptr);
            printf("\nBerhasil menghapus data di node terakhir.\n");
        }
        else
        {
            printf("\nMaaf, anda belum memasukkan data.\n");
        }
        break;
    case 2:
        break;

    default:
        break;
    }
    char enter;
    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    system("clear");
    return head;
}

void displayTable(struct node *head)
{
    system("clear");
    struct node *ptr;
    ptr = head;
    int count = 0;

    printf("-------------------------------------------------------------");
    printf("\n | No  | Name                       | Stock     | Price     |\n");
    printf("-------------------------------------------------------------\n");
    while (ptr->next != head)
    {
        count++;
        printf(" | %-2d  | %-26s | %-9d | %-9d |\n", count, ptr->name, ptr->stock, ptr->price);
        ptr = ptr->next;
    }
    printf(" | %-2d  | %-26s | %-9d | %-9d |\n", count + 1, ptr->name, ptr->stock, ptr->price);
    if (ptr->next == head)
    {
        count++;
    }
    if (count == 0)
    {
        printf("\tData Kosong, silakan masukkan data makanan\n");
    }
    printf("-------------------------------------------------------------\n");
}

struct node *addSebelum(struct node *head)
{
    int stok, harga, count = 0;
    char SetNama[50], nama[50];
    char enter;
    struct node *ptr, *preptr, *newNode;

awal:
    system("clear");
    displayTable(head);

    if (head != NULL)
    {
        printf("\nSebelum nama makanan apa anda akan tambahkan \n(masukkan sesuai nama di table): ");
        scanf("\n%[^\n]", SetNama);
        ptr = head;
        while (ptr->next != head)
        {
            if (strcmp(ptr->name, SetNama) == 0)
            {
                count++;
            }
            ptr = ptr->next;
        }
        if (ptr->next == head)
        {
            count++;
        }
        if (count == 0)
        {
            printf("\nData tidak ditemukan, silakan masukkan nama makanan sesuai table.\n");
            printf("\nKlik \"enter\" untuk lanjut : ");
            getchar();
            scanf("%c", &enter);
            goto awal;
        }
        printf("\nNama Makanan : ");
        scanf("\n%[^\n]", nama);
        printf("Stok         : ");
        scanf("%d", &stok);
        printf("Harga        : ");
        scanf("%d", &harga);

        newNode = (struct node *)malloc(sizeof(struct node));
        ptr = head;
        while (ptr->next != head)
        {
            if (strcmp(head->name, SetNama) == 0)
            {
                head = newNode;
                strcpy(newNode->name, nama);
                newNode->stock = stok;
                newNode->price = harga;
                newNode->next = ptr;
            }
            else if (strcmp(ptr->name, SetNama) == 0)
            {
                preptr->next = newNode;
                strcpy(newNode->name, nama);
                newNode->stock = stok;
                newNode->price = harga;
                newNode->next = ptr;
                break;
            }
            preptr = ptr;
            ptr = ptr->next;
        }
        printf("\nData \"%s\" berhasil ditambahkan\n", nama);
    }
    else
    {
        printf("\nMaaf, silakan masukkan data makanan terlebih dahulu\n");
    }
end:

    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    return head;
}

struct node *addSesudah(struct node *head)
{
    int stok, harga;
    char SetNama[50], nama[50];
    struct node *ptr, *preptr, *newNode;
    char enter;

    displayTable(head);

    if (head != NULL)
    {
        printf("\nSetelah nama makanan apa anda akan tambahkan \n(masukkan sesuai nama di table): ");
        scanf("\n%[^\n]", SetNama);
        printf("\nNama Makanan : ");
        scanf("\n%[^\n]", nama);
        printf("Stok         : ");
        scanf("%d", &stok);
        printf("Harga        : ");
        scanf("%d", &harga);

        newNode = (struct node *)malloc(sizeof(struct node));
        ptr = head;
        while (ptr->next != head)
        {
            if (strcmp(ptr->name, SetNama) == 0)
            {
                preptr = ptr->next;
                ptr->next = newNode;
                strcpy(newNode->name, nama);
                newNode->stock = stok;
                newNode->price = harga;
                newNode->next = preptr;
                printf("\nData \"%s\" berhasil ditambahkan\n", nama);
                goto akhirr;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        printf("\nMaaf, silakan masukkan data makanan terlebih dahulu\n");
    }
akhirr:

    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    return head;
}

struct node *otherAdd(struct node *head)
{
    int pilih;
    printf("\nMenu tambahan : \n");
    printf("1. Tambahkan data makanan, \"sebelum\" nama makanan tertentu.\n");
    printf("2. Tambahkan data makanan, \"sesudah\" nama makanan tertentu.\n");
    printf("\nPilih : ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        head = addSebelum(head);
        system("clear");
        break;
    case 2:
        head = addSesudah(head);
        system("clear");
        break;

    default:
        break;
    }
    return head;
}

struct node *hapusSebelum(struct node *head)
{
    int count = 0;
    char SetNama[50];
    char enter;
    struct node *ptr, *preptr1, *preptr2;

awal:
    system("clear");
    displayTable(head);

    if (head != NULL)
    {
        printf("\nSebelum nama makanan apa anda akan hapus datanya \n(masukkan sesuai nama di table): ");
        scanf("\n%[^\n]", SetNama);
        ptr = head;
        while (ptr->next != head)
        {
            if (strcmp(ptr->name, SetNama) == 0)
            {
                count++;
            }
            ptr = ptr->next;
        }
        if (ptr->next == head)
        {
            count++;
        }
        if (count == 0)
        {
            printf("\nData tidak ditemukan, silakan masukkan nama makanan sesuai table.\n");
            printf("\nKlik \"enter\" untuk lanjut : ");
            getchar();
            scanf("%c", &enter);
            goto awal;
        }

        ptr = head;
        while (ptr->next != head)
        {
            if (strcmp(head->name, SetNama) == 0)
            {
                printf("\nJika ingin hapus list awal bukan disini.\n");
                goto end;
            }
            else if (strcmp(ptr->name, SetNama) == 0)
            {
                preptr2->next = ptr;
                free(preptr1);
            }

            preptr2 = preptr1;
            preptr1 = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == head)
        {
            if (strcmp(ptr->name, SetNama) == 0)
            {
                preptr2->next = ptr;
                free(preptr1);
            }
        }
        printf("\nData makanan sebelum \"%s\" berhasil dihapus\n", SetNama);
    }
    else
    {
        printf("\nMaaf, silakan masukkan data makanan terlebih dahulu\n");
    }
end:

    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    return head;
}

struct node *hapusSesudah(struct node *head)
{
    int count = 0;
    char SetNama[50];
    char enter;
    struct node *temp, *ptr, *afterptr;

awal:
    system("clear");
    displayTable(head);

    if (head != NULL)
    {
        printf("\nSetelah nama makanan apa anda akan hapus datanya \n(masukkan sesuai nama di table): ");
        scanf("\n%[^\n]", SetNama);
        ptr = head;
        while (ptr->next != head)
        {
            if (strcmp(ptr->name, SetNama) == 0)
            {
                count++;
            }
            ptr = ptr->next;
        }
        if (ptr->next == head)
        {
            count++;
        }
        if (count == 0)
        {
            printf("\nData tidak ditemukan, silakan masukkan nama makanan sesuai table.\n");
            printf("\nKlik \"enter\" untuk lanjut : ");
            getchar();
            scanf("%c", &enter);
            goto awal;
        }

        ptr = head;
        while (ptr->next != head)
        {
            if (strcmp(ptr->name, SetNama) == 0)
            {
                temp = ptr;
                ptr = ptr->next;
                afterptr = ptr->next;
                temp->next = afterptr;
                free(ptr);
                printf("\nData makanan setelah \"%s\" berhasil dihapus\n", SetNama);
                goto end;
            }
            ptr = ptr->next;
        }
        if(ptr->next == head)
        {
            printf("\nTidak ada data setelah data terakhir!\n");
        }
    }
    else
    {
        printf("\nMaaf, silakan masukkan data makanan terlebih dahulu\n");
    }
end:

    getchar();
    printf("\nKlik \"enter\" untuk kembali ke menu : ");
    scanf("%c", &enter);
    return head;
}

struct node *otherDelete(struct node *head)
{
    int pilih;
    printf("\nMenu tambahan : \n");
    printf("1. Hapus data makanan, \"sebelum\" nama makanan tertentu.\n");
    printf("2. Hapus data makanan, \"sesudah\" nama makanan tertentu.\n");
    printf("\nPilih : ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        head = hapusSebelum(head);
        system("clear");
        break;
    case 2:
        head = hapusSesudah(head);
        system("clear");
        break;

    default:
        break;
    }
    return head;
}

int main()
{
    system("clear");
    int pilih;
    struct node *head = NULL;
    printf("\n---------------------------------------------------------------\n");
    printf("   Circular Single Linked List (CSLL) A P P L I C A T I O N\n");
    printf("---------------------------------------------------------------\n");

    printf("\nThis program using food menu, example :\n");
    printf("-------------------------------------------------------------");
    printf("\n | No  | Name                       | Stock     | Price     |\n");
    printf("-------------------------------------------------------------\n");
    printf(" | 1.  | Chicken Pop Salted Egg     | 21        | Rp25,000  |\n");
    printf("-------------------------------------------------------------\n");
awal:
    printf("\nMenu of the program :\n");
    printf("\n1. Insert The Food Menu List\n");
    printf("2. Add Food Menu at the beginning\n");
    printf("3. Add Food Menu at the end\n");
    printf("4. Other addition schemes node ...\n");
    printf("5. Delete the first Food Menu\n");
    printf("6. Delete the last Food Menu\n");
    printf("7. Other deletion schemes node ...\n");
    printf("8. Display Food Menu\n");
    printf("0. Exit\n");
    printf("\nPilih : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        head = addFood(head);
        goto awal;
        break;
    case 2:
        head = addBeginning(head);
        goto awal;
        break;
    case 3:
        head = addEnd(head);
        goto awal;
        break;
    case 4:
        head = otherAdd(head);
        goto awal;
        break;
    case 5:
        head = deleteFirst(head);
        goto awal;
        break;
    case 6:
        head = deleteLast(head);
        goto awal;
        break;
    case 7:
        head = otherDelete(head);
        goto awal;
        break;
    case 8:
        displayTable(head);
        goto awal;
        break;
    case 0:
        break;
    default:
        break;
    }
}