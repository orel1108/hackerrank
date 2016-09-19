std::cout << std::setw(0);

long long a = static_cast<long long>(A);
cout << nouppercase << "0x" << hex << a << endl;

cout << setw(15) << setfill('_') << right <<  showpos << fixed << setprecision(2) << B << endl;

cout << setw(0);
std::cout << std::resetiosflags(std::ios::adjustfield);
cout << noshowpos;

cout.precision(9);
cout << uppercase << scientific << C << endl;
