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
        //for (int i = 0; i < q.size(); i++)
          //  printf("%d ", q[i]);
        printf("\n");
     }

};

class Graph
{
public:
    int V; //no.of.vertices
    vector<int> *Edge; //adjacency_list
    int *visited;

    vector<int> vec;
    vector< vector<int> > Connected_Components;
    vector<int> stack;


    Graph(int total_vertices)
    {
        V = total_vertices;
        Edge = new vector<int>[total_vertices];
        visited = new int[V];
        clear_visited_array();
    }

    ~Graph() { delete[] Edge; delete[] visited;}

    void Add_Edge(int a, int b)
    {
        Edge[a].push_back(b);
        //Edge[b].push_back(a);
    }

    void clear_visited_array()
    {
          // 1) mark all nodes as not visited
          for (int i=0; i<V; i++)
              visited[i] = 0;

    }

    void print()
    {
        printf("Total Vertices: %d\n", V);
        for (int i=0; i<V; i++)
            for (int j=0; j<Edge[i].size(); j++)
                printf("Edge: [%d,%d]=1\n", i,Edge[i][j]);
    }

    void print_DFS()
    {
        // print DFS array
        printf("\nDFS: ");
        for (int i=0; i<vec.size(); i++)
            printf("%d ", vec[i]);
    }

    void BFS(int s)
    {
        vector<int> BFS_array;
        // 1) mark all nodes as unvisited
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

    }

    void DFS_traversal(int s)
    {
        if (visited[s] == 0)
        {
            visited[s] = 1;
            vec.push_back(s);
            // go through neighbor/adjacent nodes
            int current_size = vec.size();
            for (int j=0; j<Edge[s].size(); j++)
            {
                int l = Edge[s][j];
                //recursively explore adjacent edge
                DFS_traversal(l);
            }
            if (is_All_Adj_nodes_are_Visited(s))
                stack.push_back(s);
        }
    }

    void DFS(int s)
    {
        vec.clear();
        DFS_traversal(s);
    }

    void Transpose_Graph()
    {
        vector<int> *Temp_Edge = new vector<int>[V];
        for (int i=0; i<V; i++)
        {
            for (int j=0; j<Edge[i].size(); j++)
                Temp_Edge[Edge[i][j]].push_back(i);
        }
        delete[] Edge;
        vector<int> *Edge = new vector<int>[V];
        for (int i=0; i<V; i++)
            for (int j=0; j<Temp_Edge[i].size(); j++)
                Edge[i].push_back(Temp_Edge[i][j]);
        delete[] Temp_Edge;
        printf("\nTransposed Graph:\n");
        print();
    }

    int is_All_Adj_nodes_are_Visited(int s)
    {
         for (int j=0; j<Edge[s].size(); j++)
            if (visited[s] == 0)
                return 0;

         return 1;
    }

    void print_SCC() //strongly connected components
    {

        // 1) perform DFS from a source node: O(V+E)
        int s = 0;
        stack.clear();
        vec.clear();
        DFS(s);
        print_DFS();

        // print stack
        printf("\nStack: ");
        for (int i=0; i<stack.size(); i++)
            printf("%d ", stack[i]);

        // 2) Transpose the graph: O(E)
        Transpose_Graph();

        // 3) Pop elements from stack and perform DFS on transposed graph: O(V+E)
        clear_visited_array();
        vector<int> new_stack = stack;
        for (int i=new_stack.size()-1; i>=0; i--)
        {
            int elem = new_stack[i];
            DFS(elem);
            print_DFS();

            if (!vec.empty())
                Connected_Components.push_back(vec);
        }

        // 4) print SCC: final complexity = O(V+E)
        printf("\nStrongly Connected Components:\n");
        for (int i=0; i<Connected_Components.size(); i++)
        {
            for (int j=0; j<Connected_Components[i].size(); j++)
                printf("%d ", Connected_Components[i][j]);
            printf("\n");
        }

    }
};

