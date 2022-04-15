int main() {
    std::cout << "Hello World!\n";
    
    stringstream ss( "1,1,1,1, or something else ,1,1,1,0" );
    vector<string> result;

    while( ss.good() )
    {
        string substr;
        getline( ss, substr, ',' );
        result.push_back( substr );
    }
    for (auto s:result) printf("%s\n", s.c_str());
}