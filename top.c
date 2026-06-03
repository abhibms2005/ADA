#include <stdio.h>

int graph[10][10];
int indegree[10];
int result[10];
int stack[10];

int numVertices;
int top = -1;
int resultIndex = 0;

/* Read adjacency matrix */
void readGraph()
{
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

/* Topological sorting (Kahn's Algorithm) */
void topologicalSort()
{
    int currentNode;

    // Step 1: Calculate indegree of each vertex
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    // Step 2: Push all nodes with indegree 0 into stack
    for (int i = 0; i < numVertices; i++)
    {
        if (indegree[i] == 0)
        {
            stack[++top] = i;
        }
    }

    // Step 3: Process stack
    while (top != -1)
    {
        currentNode = stack[top--];
        result[resultIndex++] = currentNode;

        for (int i = 0; i < numVertices; i++)
        {
            if (graph[currentNode][i] == 1)
            {
                indegree[i]--;

                if (indegree[i] == 0)
                {
                    stack[++top] = i;
                } 
            }
        }
    }
}

int main()
{
    readGraph();
    topologicalSort();

    // Check if topological sort is possible
    if (resultIndex == numVertices)
    {
        printf("\nTopological Order:\n");

        for (int i = 0; i < numVertices; i++)
        {
            printf("%d ", result[i]);
        }
    }
    else
    {
        printf("\nTopological ordering not possible (graph has cycle)\n");
    }

    return 0;
}