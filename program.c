#include<stdio.h>
struct hairsalon
{
    char name[20];
    char activity[20];
}e[50];
int size=0,b;

display_activity()
{

    FILE *file;
    char buffer[100];
    int count = 0;

    // Open the file for reading
    file = fopen("students.txt", "r");

    // Read a line from the file and print it to the console
    printf("\n\n");
    printf("=========== Activities ========== \n");
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("\n%s", buffer);
    }
}
void addRecord(char name[20],char activity[20])
{
    FILE *file;
    int roll;
    // Open the file for writing, and append to the end of the file if it exists
    file = fopen("students.txt", "a");

    // Get the student's details
    printf("Enter the roll number: ");
    scanf("%d", &roll);

    // Write the record to the end of the file
    fprintf(file, "%d %s %s\n", roll, name,activity);

    // Close the file
    fclose(file);
}
void deleteRecord(int id)

   {
    FILE *input_file, *output_file;
    char buffer[100], temp_file[] = "temp.txt";
    int line_number, current_line = 1;

    // Open the file for reading and writing
    input_file = fopen("students.txt", "r+");

    // Open the output file for writing
    output_file = fopen(temp_file, "w");

    char str[10];

    //convert int to str
    sprintf(str, "%d", id);

    // Copy all lines except for the specified line to a temporary file
    while(fgets(buffer, sizeof(buffer), input_file) != NULL) {
        if(strstr(buffer, str) == NULL) {
            fputs(buffer, output_file);
        }
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Delete the original file
    remove("students.txt");

    // Rename the temporary file to the original filename
    rename(temp_file, "students.txt");
}
void searchRecord(char name[20])
{

    FILE *file;
    char buffer[100];
    int count = 0;

    // Open the file for reading
    file = fopen("students.txt", "r");

    printf("\n\n");
    printf("## Search Result: %s \n",name);
    printf("\n================");

    // Read a line from the file and print it to the console
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        if(strstr(buffer, name) != NULL) {
            printf("\n%s", buffer);
            // fclose(file);

        }
    }

    // Close the file
    fclose(file);

}
int main()

{
    printf("enter the customer information:\n");
    printf("enter the name:...");
    scanf("%s",e[size].name);
    printf("enter the activity:....");
    scanf("%s",e[size].activity);
    // size++;

    printf("\nMain Menu\n======\n");
    printf("\n1.display_activity\n2.addRecord\n3.deleteRecord\n4.searchRecord\n0 Exit\n Make a choice:....");
    scanf("%d",&b);
    int num;
    do
    {

        switch(b)
        {
        case 1:
            display_activity();
            break;
        case 2:
            addRecord(e[size].name,e[size].activity);
            break;
        case 3:
            int id;
            printf("\n\n Enter User Id: ");
            scanf("%d",&id);
            deleteRecord(id);
            break;
        case 4:
            searchRecord(e[size].name);
            break;
        case 5:
            printf("good bye");
            break;
        default:
            printf("wrong choice! choose again...");
        }
        num = 5;
    }while(num == b);
}
