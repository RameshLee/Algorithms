
// Template example
template<typename T>
T maximum(T i, T j){
    if (i>j) return i;
    return j;
}

int main()
{
    // Map in which key is a pair.
    map<pair<string,string>,int> Map =
    {
        {{"Hash","Map"},2011},
        {{"BST","Map"},2014}
    };

    for (auto it=Map.begin(); it!=Map.end(); it++){

        pair<string,string> p = it->first;
        printf("{%s, %s}\n",p.first.c_str(), p.second.c_str());
    }

     pair<string,string> p = make_pair("Hash","Map");
        printf("Here: %d\n", Map[p]);

    int i=2; int j=4;
    printf("Max value among (%d,%d) is %d\n", i,j, maximum<int>(i,j));

    return 0;
}