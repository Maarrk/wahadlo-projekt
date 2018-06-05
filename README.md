# Wahadło - projekt

Projekt na zaliczenie Informatyki 2 w semestrze 2017L.

Temat: wahadło z dużym wychyleniem

## Obsługa

Żeby przystosować kod do swojego projektu należy zmienić kilka linijek w `main.cpp`. Jeśli zapis w kodzie jest niejasny to całe sprawozdanie jest w `wahadlo-projekt/R-project/test.pdf`

----------

Zapis do pliku -  zamienić `cout` na `fout` tutaj (na mojej Informatyce chyba nie było strumieni)
```cpp
cout << "t\talfa\tomega\tenergia\n";
for (int i = 0; i < 100; i++) {
	cout << t0 + i*h << "\t" << y[i][0] << "\t" << y[i][1] << "\t" << e_mech(y[i][0], y[i][1]) << endl;
}
```

## Uruchomienie

Cały projekt siedzi tak naprawdę w `main.cpp`, wystarczy skompilować to z załączonym `rk4.h` i `rk4.cpp`. Wystarczy notatnik i kompilator.

Jeśli tak komuś wygodniej to projekt powinien się dać otworzyć w Visual Studio 15 lub nowszym przez `Wahadlo.sln`