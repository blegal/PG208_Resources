#include <iostream>
#include <strings.h>
#include <assert.h>

using namespace std;

class Matrice{
private:
    int* _array;
    int  _width;
    int _height;

public:
    Matrice(const int x, const int y)
    {
        assert( x != 0 );
        assert( y != 0 );

        _array  = new int[x * y];
        bzero(_array, x * y * sizeof(int));
        _width  = x;
        _height = y;
    }

    Matrice(Matrice* m)
    {
        _array  = new int[m->width() * m->height()];
        _width  = m->width ();
        _height = m->height();

        // ON COPIE LES DONNEES
        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width(); x++){
                set(x, y, m->get(x, y));
            }            
        }
    }

    ~Matrice()
    {
        delete[] _array;
    }

    int width() const 
    {
        return _width;
    }

    int height() const 
    {
        return _height;
    }

    Matrice* clone()
    {
        return new Matrice(this);
    }

    int get(const int x, const int y) const 
    {
        assert( x < width () );
        assert( y < height() );
        return _array[y * width() + x];
    }

    void set(const int x, const int y, const int value)
    {
        assert( x < width () );
        assert( y < height() );
        _array[y * width() + x] = value;
    }

    void show( ) const 
    {
        cout << "Matrice " << width() << " x " << height() << endl;
        for(int y = 0; y < height(); y++){
            cout << y << " [";
            for(int x = 0; x < width(); x++){
                cout.width (4);
                cout << get(x, y) << ((x!=width()-1)?" ":"");
            }            
            cout << "]" << endl;
        }
        cout << endl;
    }

    void add(const int value)
    {
        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width(); x++){
                set(x, y, get(x, y) + value);
            }            
        }
    }

    void sub(const int value)
    {
        add( -value );
    }

    void mult(const int value)
    {
        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width(); x++){
                set(x, y, get(x, y) * value);
            }            
        }
    }

    Matrice* add(const Matrice *m)
    {
        assert( width()  == m->width()  );
        assert( height() == m->height() );

        Matrice* r = new Matrice(width(), height());

        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width(); x++){
                r->set(x, y, get(x,y) + m->get(x,y));
            }            
        }

        return r;
    }

    Matrice* mult(const Matrice *m)
    {
        assert( height() == m->width() );

        Matrice* r = new Matrice(m->width(), height());

        for(int y = 0; y < r->height(); y++){
            for(int x = 0; x < r->width(); x++){
                int sum = 0;
                for(int z = 0; z < width(); z++){
                    sum += get(z,y) * m->get(x,z);
                }
                r->set(x, y, sum);
            }
        }

        return r;
    }

    void rotate90( )
    {
        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width()/2; x++){
                int tmp = get(x, y);
                set(x,         y,   get(x, width()-y-1));
                set(x, width()-y-1, tmp);
            }            
        }
    }

    int min( ) const 
    {
        int mini = +100000000;
        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width(); x++){
                mini = mini < get(x, y) ? mini : get(x, y);
            }            
        }
        return mini;
    }

    int max( ) const 
    {
        int maxi = -100000000;
        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width(); x++){
                maxi = maxi > get(x, y) ? maxi : get(x, y);
            }            
        }
        return maxi;
    }

    int sum( )
    {
        int sums = 0;
        for(int y = 0; y < height(); y++){
            for(int x = 0; x < width(); x++){
                sums += get(x, y);
            }            
        }
        return sums;
    }

    int avg( )
    {
        return sum( ) / (width() * height());
    }

};

    bool operator==(const Matrice& lhs, const Matrice& rhs)
    {
        if( lhs.width () == rhs.width () ) return false;
        if( lhs.height() == rhs.height() ) return false;
        for(int y = 0; y < lhs.height(); y++){
            for(int x = 0; x < lhs.width(); x++){
                if( lhs.get(x, y) == rhs.get(x, y) ){
                    return false;
                }
            }
        }
        return true;
    }

std::ostream& operator<<(std::ostream& out, const Matrice& lhs)
{
   return out << lhs.width() << 'x' << lhs.height() ;
}

bool operator!=(const Matrice& lhs, const Matrice& rhs)
{
    return !(lhs == rhs);
}

Matrice operator*(Matrice lhs, const Matrice& rhs)
{
    return lhs.mult( &rhs );
}

Matrice operator+(Matrice lhs, const Matrice& rhs)
{
    return lhs.add( &rhs );
}

Matrice operator+(Matrice lhs, const int rhs)
{
    lhs.mult( rhs );
    return lhs;
}

int main(int argc, char* argv[]) {

    // TEST DES FONCTIONNALITES DE BASE

    Matrice* m1 = new Matrice(3, 2);

    for(int x=0; x<m1->width(); x++){
        for(int y=0; y<m1->height(); y++){
            m1->set(x, y, rand()%10);
        }
    }

    cout << *m1 << endl;

    m1->show( );

    m1->add( 2 );
    
    m1->show( );

    m1->add( -2 );
    
    m1->show( );

    m1->mult( -1 );
    
    m1->show( );

    // TEST DE L'ADDITION DE MATRICE DE MEME RANG

    Matrice* m2 = new Matrice(3, 2);

    for(int x=0; x<m2->width(); x++){
        for(int y=0; y<m2->height(); y++){
            m2->set(x, y, rand()%10);
        }
    }

    m2->show( );

    Matrice* m3 = m1->add( m2 );

    m3->show( );

    delete m2;
    delete m3;

    // TEST DE LA MULTPLICATION DE MATRICE

    Matrice* m4 = new Matrice(2, 3);

    for(int x=0; x<m4->width(); x++){
        for(int y=0; y<m4->height(); y++){
            m4->set(x, y, rand()%10);
        }
    }

    m1->show( );
    m4->show( );

    Matrice* m5 = m1->mult( m4 );

    m5->show( );

    delete m1;
    delete m4;
    delete m5;

    return 0;
}

