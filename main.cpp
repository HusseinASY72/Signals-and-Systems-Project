#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

const int Max = 100;
void selectf();
void convolutionf();
void deconvolutionf();
void deconvolution(int h[], int y[], int x[], int h_size, int y_size);
void show_signal(const char *name, int signal[], int size);
void show_signalx(int signal[], int size);
int inputf(string xyz, int z[1000], int ns);
void showf(string xyz, int z[1000], int ns, int n0);
void n0(int z[Max], int n0v);

int main()
{
    char input;
    int sw;
    int w = 0;
    do
    {
        system("cls");
        cout << "Convolution and Deconvolution in C++\n\nCreated by:\nHussein Ahmed Saeed\nAbrar Alaa Abdulsalam" << endl;
        cout << "\n\nEnter any thing to start" << endl;
        cout << "\nenter:";
        cin >> input;
        system("cls");
        selectf();
        w = 0;
        cout << "\nMain Menu[0]" << endl;
        do
        {
            cout << "\nenter:";
            cin >> sw;
            switch (sw)
            {
            case 0:
            {
                system("cls");
            }
            break;
            default:
            {
                cout << "This option is not available!" << endl;
                sw = 1;
            }
            }
        } while (sw == 1);
    } while (w == 0);
    return 0;
}

void selectf()
{
    char select;
    cout << "Select the operation:\nConvolution[1]\nDeconvolution[2]" << endl;
    do
    {
        cout << "\nenter:";
        cin >> select;
        switch (select)
        {
        case '1':
        {
            system("cls");
            convolutionf();
        }
        break;
        case '2':
        {
            system("cls");
            deconvolutionf();
        }
        break;
        default:
        {
            cout << "This option is not available!" << endl;
            select = '?';
        }
        }
    } while (select == '?');
}

void convolutionf()
{
    int samcount = 1;
    string xyz;
    int input;
    int indz = 0;
    int x[1000];
    int h[1000];
    int y[1000];
    int nsx;  // number of samples(x)
    int nsh;  // number of samples(h)
    int nsy;  // number of samples(y)
    int nsxv; // variable of number of samples(x)
    int nshv; // variable of number of samples(h)
    int nsyv; // variable of number of samples(y)
    int sns;  // summation of numbers of samples
    int n0x;  // n=0 in x(n)
    int n0xv;
    int n0h; // n=0 in h(n)
    int n0hv;
    int n0y; // n=0 in y(n)
    int n0yv;
    int arrmult[1000]; // array of multiplied samples
    int lc = 0;        // counter of loop
    int rep = 0;       // repeat variable
    int j = 0, k = 0;  // variables of multiplication loops
    int shift;         // shifting variable for summation
    int sum;
    int w = 0; // while variable
    int sw;
    int cvar = 1;
    // reset of arrays
    indz = 1000;
    while (indz > 0)
    {
        indz--;
        x[indz] = 0;
        h[indz] = 0;
        y[indz] = 0;
        arrmult[indz] = 0;
    }
    // end reset of arrays
    // array of x(n)
    cout << "Enter the size of x(n):" << endl;
    do
    {
        samcount--;
        if (samcount < 0)
        {
            cout << "This number is not allowed!" << endl;
        }
        cout << "\nenter:";
        cin >> nsx;
    } while (nsx <= 0);
    samcount = 1;
    nsxv = nsx;
    system("cls");
    indz = 0;
    cout << "Enter the x(n) samples:" << endl;
    do
    {
        cout << "\nEnter sample " << samcount << ":";
        cin >> input;
        x[indz] = input;
        nsxv = nsxv - 1;
        indz++;
        samcount++;
    } while (nsxv > 0);
    // end array of x(n)
    system("cls");
    xyz = "x(n)";
    n0x = inputf(xyz, x, nsx);
    // array of h(n)
    cout << "Enter the size of h(n):" << endl;
    do
    {
        samcount--;
        if (samcount < 0)
        {
            cout << "This number is not allowed!" << endl;
        }
        cout << "\nenter:";
        cin >> nsh;
    } while (nsh <= 0);
    samcount = 1;
    nshv = nsh;
    system("cls");
    indz = 0;
    cout << "Enter the h(n) samples:" << endl;
    do
    {
        cout << "\nEnter sample " << samcount << ":";
        cin >> input;
        h[indz] = input;
        nshv = nshv - 1;
        indz++;
        samcount++;
    } while (nshv > 0);
    // end array of h(n)
    system("cls");
    xyz = "h(n)";
    n0h = inputf(xyz, h, nsh);
    // multiplication and
    nsxv = nsx;
    nshv = nsh;
    indz = 0;
    j = 0;
    k = 0;
    lc = 0;
    while (nsxv > 0)
    {
        nsxv--;
        while (nshv > 0)
        {
            arrmult[indz] = x[j] * h[k];
            nshv--;
            indz++;
            k++;
        }
        indz = lc + 50;
        k = 0;
        j++;
        nshv = nsh;
        lc = lc + 50;
    }
    // end multiplication
    // summation
    nsxv = nsx;
    nshv = nsh;
    indz = 0;
    shift = 0;
    sns = nsx + nsh;
    nsy = sns - 1;
    while (nsy > 0)
    {
        nsy--;
        sum = 0;
        while (nsxv > 0)
        {
            nsxv--;
            sum = sum + arrmult[indz + shift];
            shift = shift + 50;
            shift--;
        }
        y[indz] = sum;
        indz++;
        shift = 0;
        nsxv = nsx;
    }
    // end summation
    system("cls");
    // show y(n),x(n),h(n)
    sns = nsx + nsh;
    nsy = sns - 1;
    n0y = n0x + n0h;
    cout << "Result of convolution:" << endl;
    xyz = "y(n)";
    showf(xyz, y, nsy, n0y);
    cout << "\nWe found y(n) from x(n) and y(n):" << endl;
    xyz = "x(n)";
    showf(xyz, x, nsx, n0x);
    xyz = "h(n)";
    showf(xyz, h, nsh, n0h);
    // end show y(n),x(n),h(n)
}

void deconvolutionf()
{
    int h[Max], y[Max], x[Max];
    int size_h, size_y;
    int n0h = 0, n0y = 0;
    int k = 0;

    cout << "Enter the size of h(n):" << endl;
    cout << "\nenter:";
    cin >> size_h;
    system("cls");
    cout << "Enter the h(n) samples:\n"
         << endl;
    for (int i = 0; i < size_h; i++)
    {
        cout << "Enter sample " << i + 1 << ":";
        cin >> h[i];
        cout << endl;
    }
    system("cls");
    cout << "Determine the (n=0):" << endl;
    show_signal("h(n)", h, size_h);
    cout << "\nenter:";
    cin >> n0h;
    system("cls");
    cout << "(" << h[n0h - 1] << ") is (n=0) in h(n):\n"
         << endl;
    show_signal("h(n)", h, size_h);
    n0(h, n0h);
    cout << "Continue[0]" << endl;
    cout << "\nenter:";
    cin >> k;

    system("cls");
    cout << "Enter the size of y(n):" << endl;
    do
    {
        if (k == 1)
        {
            cout << "The size of y(n) should be larger than the size of h(n)!" << endl;
        }
        cout << "\nenter:";
        cin >> size_y;
        k = 1;
    } while (size_y <= size_h);
    k = 0;
    system("cls");
    cout << "Enter the y(n) samples:\n"
         << endl;
    for (int i = 0; i < size_y; i++)
    {
        cout << "Enter sample " << i + 1 << ":";
        cin >> y[i];
        cout << endl;
    }
    system("cls");
    cout << "Determine the (n=0):" << endl;
    show_signal("y(n)", y, size_y);
    cout << "\nenter:";
    cin >> n0y;
    system("cls");
    cout << "(" << y[n0y - 1] << ") is (n=0) in y(n):\n"
         << endl;
    show_signal("y(n)", y, size_y);
    n0(y, n0y);
    cout << "Continue[0]" << endl;
    cout << "\nenter:";
    cin >> k;

    int x_size = size_y - size_h + 1;
    int n0x;
    bool bn0x = false;
    if (n0y == 1 && n0h == 1)
    {
        n0x = 1;
    }
    else
    {
        if (n0y > 1 && n0h == 1)
        {
            n0x = n0y;
        }
        else
        {
            if (n0y == 1 && n0h > 1)
            {
                n0x = n0h - 1;
                bn0x = true;
            }
            else if (n0y > 1 && n0h > 1)
            {
                n0x = 1 + n0y - n0h;
            }
        }
    }

    deconvolution(h, y, x, size_h, size_y);

    show_signal("h(n)", h, size_h);
    show_signal("y(n)", y, size_y);
    system("cls");

    cout << "x(n)=[";
    if (bn0x)
    {
        for (int i = 0; i < n0x; i++)
        {
            cout << "0,";
        }
    }
    show_signalx(x, x_size);
    if (bn0x)
    {
        n0(x, n0x - 1);
    }
    else
    {
        n0(x, n0x);
    }
    cout << "\nWe found x(n) from h(n) and y(n):" << endl;
    show_signal("h(n)", h, size_h);
    n0(h, n0h);
    show_signal("y(n)", y, size_y);
    n0(y, n0y);
    return;
}

void deconvolution(int h[], int y[], int x[], int h_size, int y_size)
{
    int x_size = y_size - h_size + 1;
    for (int i = 0; i < x_size; i++)
    {
        x[i] = y[i];
        for (int j = 1; j < h_size; j++)
        {
            if (i - j >= 0)
            {
                x[i] = x[i] - (h[j] * x[i - j]);
            }
        }
        x[i] /= h[0];
    }
}

void show_signal(const char *name, int signal[], int size)
{
    cout << name << "=[";
    for (int i = 0; i < size; i++)
    {
        cout << signal[i];
        if (i < size - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

void show_signalx(int signal[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << signal[i];
        if (i < size - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

int inputf(string xyz, int z[1000], int ns)
{
    system("cls");
    int n0;
    int n0v = n0;
    int input;
    int indz = 0;
    int nsv;
    int w = 0;
    int sw = 0;
    // n=0 in z(n)
    if (ns > 1)
    {
        cout << "Determine the (n=0):" << endl;
        indz = 0;
        nsv = ns;
        cout << xyz << "=[";
        while (nsv > 1)
        {
            cout << z[indz] << ",";
            nsv--;
            indz++;
        }
        cout << z[indz] << "]" << endl;
        while (w == 0)
        {
            cout << "\nenter:";
            cin >> input;
            if (input > ns || input <= 0)
            {
                cout << "This value is not exist in " << xyz << "!" << endl;
            }
            else
            {
                n0 = input - 1;
                n0v = n0;
                system("cls");
                cout << "(" << z[input - 1] << ") is (n=0) in " << xyz << ":\n"
                     << endl;
                indz = 0;
                cout << xyz << "=[";
                nsv = ns;
                while (nsv > 1)
                {
                    cout << z[indz] << ",";
                    nsv--;
                    indz++;
                }
                cout << z[indz] << "]" << endl;
                indz = 0;
                cout << "      ";
                while (n0v > 0)
                {
                    cout << "  ";
                    if (z[indz] < -99)
                    {
                        cout << " ";
                    }
                    if (z[indz] < -9)
                    {
                        cout << " ";
                    }
                    if (z[indz] < 0)
                    {
                        cout << " ";
                    }
                    if (z[indz] > 9)
                    {
                        cout << " ";
                    }
                    if (z[indz] > 99)
                    {
                        cout << " ";
                    }
                    n0v--;
                    indz++;
                }
                cout << "^" << endl;
                w = 1;
            }
        }
        w = 0;
        cout << "Continue[0]" << endl;
        do
        {
            cout << "\nenter:";
            cin >> sw;
            switch (sw)
            {
            case 0:
            {
                system("cls");
            }
            break;
            default:
            {
                cout << "This option is not available!" << endl;
                sw = 1;
            }
            }
        } while (sw == 1);
    }
    else
    {
        n0v = 0;
    }
    // end n=0 in z(n)
    system("cls");
    return n0;
}

void showf(string xyz, int z[1000], int ns, int n0)
{
    int indz = 0;
    int n0v = n0;
    int nsv = ns;
    cout << xyz << "=[";
    while (nsv > 1)
    {
        cout << z[indz] << ",";
        nsv--;
        indz++;
    }
    cout << z[indz] << "]" << endl;
    indz = 0;
    cout << "      ";
    while (n0v > 0)
    {
        cout << "  ";
        if (z[indz] < -99)
        {
            cout << " ";
        }
        if (z[indz] < -9)
        {
            cout << " ";
        }
        if (z[indz] < 0)
        {
            cout << " ";
        }
        if (z[indz] > 9)
        {
            cout << " ";
        }
        if (z[indz] > 99)
        {
            cout << " ";
        }
        n0v--;
        indz++;
    }
    cout << "^" << endl;
}

void n0(int z[Max], int n0v)
{
    int indz = 0;
    cout << "    ";
    while (n0v > 0)
    {
        cout << "  ";
        if (z[indz] < -99)
        {
            cout << " ";
        }
        if (z[indz] < -9)
        {
            cout << " ";
        }
        if (z[indz] < 0)
        {
            cout << " ";
        }
        if (z[indz] > 9)
        {
            cout << " ";
        }
        if (z[indz] > 99)
        {
            cout << " ";
        }
        n0v--;
        indz++;
    }
    cout << "^" << endl;
}
