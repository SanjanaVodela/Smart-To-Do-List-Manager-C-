#include <stdio.h>
#include <string.h>

struct Task 
{
    char name[50];
    int completed; // 0 = pending, 1 = done
};

int main() 
{
    struct Task tasks[50];
    int n = 0;
    int choice, i, taskNo, index;

    while (1) 
    {
        printf("\n--- Smart To-Do List Manager ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter task name: ");
                scanf(" %[^\n]", tasks[n].name);  // reads full line without fgets
                tasks[n].completed = 0;
                n++;
                printf("Task added successfully!\n");
                break;

            case 2:
                if (n == 0) 
                {
                    printf("No tasks found.\n");
                } 
                else 
                {
                    printf("\nTask List:\n");
                    for (i = 0; i < n; i++) 
                    {
                        if (tasks[i].completed == 1)
                            printf("%d. %s [Done]\n", i + 1, tasks[i].name);
                        else
                            printf("%d. %s [Pending]\n", i + 1, tasks[i].name);
                    }
                }
                break;

            case 3:
                printf("Enter task number to mark as completed: ");
                scanf("%d", &taskNo);

                index = taskNo - 1;   // simple variable for clarity

                if (index >= 0 && index < n) 
                {
                    tasks[index].completed = 1;
                    printf("Task marked as completed!\n");
                } 
                else 
                {
                    printf("Invalid task number.\n");
                }
                break;

            case 4:
                printf("Enter task number to delete: ");
                scanf("%d", &taskNo);

                index = taskNo - 1;   // again, simple and readable

                if (index >= 0 && index < n) 
                {
                    for (i = index; i < n - 1; i++) 
                    {
                        tasks[i] = tasks[i + 1];
                    }
                    n--;
                    printf("Task deleted successfully!\n");
                } 
                else 
                {
                    printf("Invalid task number.\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

