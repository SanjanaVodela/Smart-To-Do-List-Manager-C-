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
    int n = 0, choice, i, taskNo;

    while(1) 
    {
        printf("\n--- Smart To-Do List Manager ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) 
        {
            case 1:
                printf("Enter task name: ");
                fgets(tasks[n].name, sizeof(tasks[n].name), stdin);
                tasks[n].name[strcspn(tasks[n].name, "\n")] = 0; // remove newline
                tasks[n].completed = 0;
                n++;
                printf("Task added successfully!\n");
                break;

            case 2:
                if(n == 0) 
                {
                    printf("No tasks found.\n");
                } 
                else 
                {
                    printf("\nTask List:\n");
                    for(i = 0; i < n; i++) 
                    {
                        printf("%d. %s [%s]\n", i+1, tasks[i].name, tasks[i].completed ? "Done" : "Pending");
                    }
                }
                break;

            case 3:
                printf("Enter task number to mark as completed: ");
                scanf("%d", &taskNo);
                if(taskNo >=1 && taskNo <= n) 
                {
                    tasks[taskNo-1].completed = 1;
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
                if(taskNo >=1 && taskNo <= n) 
                {
                    for(i = taskNo-1; i < n-1; i++) 
                    {
                        tasks[i] = tasks[i+1];
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
