Server s;
try
{
    long long res = Server::compute(A, B);
    cout << res << endl;
}
catch(std::bad_alloc e)
{
    cout << "Not enough memory" << endl;
}
catch(std::exception & e)
{
    cout << "Exception: " << e.what() << endl;
}
catch(...)
{
    cout << "Other Exception" << endl;
}
