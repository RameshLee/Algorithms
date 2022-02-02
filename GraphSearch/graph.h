// C++ header file for graph

class Queue
{
public:
    vector<int> q;

     void push(int value){
       q.insert(q.end(),value);
     }

     int pop(){
         int front = q[0];
         q.erase(q.begin());
         return front;
     }

     void print()
     {
        printf("q-contents(%lu): ", q.size());
        //for (int i = 0; q.size(); i++)
          //  printf("%d ", q[i]);
        printf("\n");
     }

};

class Graph
{
public:
    int V; //no.of.vertices
    vector<int> *Edge;

    Graph(int total_vertices)
    {
        V = total_vertices;
        Edge = new vector<int>[total_vertices];
    }

    ~Graph() { delete[] Edge;}

    void Add_Edge(int a, int b)
    {
        Edge[a].push_back(b);
        //Edge[b].push_back(a);
    }

    void print()
    {
        printf("Total Vertices: %d\n", V);
        for (int i=0; i<V; i++)
        for (int j=0; j<Edge[i].size(); j++)
            printf("Edge: [%d,%d]=1\n", i,Edge[i][j]);
    }

    void BFS(int s)
    {
        vector<int> BFS_array;
        // 1) mark all nodes as unvisited
        int *visited = new int[V];
        for (int i=0; i<V; i++)
            visited[i] = 0;

        Queue queue;
        // 2) mark node s as visited
        visited[s] = 1;
        queue.push(s);
        BFS_array.push_back(s);

        // 3) visit breath-wise
        while (queue.q.size() != 0)
        {
            int i = queue.pop();
            visited[i] = 1;

            //for all adjacent edges of "i", put it in queue
            for (int j=0; j<Edge[i].size(); j++)
            {
               int l = Edge[i][j];
               if (visited[l] == 0)
               {
                    visited[l] = 1;
                    queue.push(l);
                    BFS_array.push_back(l);
               }
            }
        }

        // print BFS array
        printf("BFS: ");
        for (int i=0; i<BFS_array.size(); i++)
            printf("%d ", BFS_array[i]);
        printf("\n");

        delete[] visited;
    }
};

