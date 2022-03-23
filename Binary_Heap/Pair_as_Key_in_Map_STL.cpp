

int main()
{
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

    return 0;
}