#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle {
    public:
        long w; long h;
        Rectangle() {
            w = 0; h=0;
        }
        void read_input(){
            int nw; int nh;
            cin >> nw >> nh;
            w = nw; h = nh;
        }
        void display(){
            cout << w << " " << h << "\n";
        }
};

class RectangleArea : public Rectangle{
    private:
        int area;    
    public:
        RectangleArea() {
            area = 0;
        }
        void read_input(){
            int nw; int nh;
            cin >> nw >> nh;
            w = nw; h = nh; area = nw*nh;
        }
        void display(){
            cout << area << "\n";
        }
};




int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}