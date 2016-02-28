class D 
{
int val;
public:
    D()
    {
        val = 1;
    }

    void update_val(int new_val)
    {
        val = new_val;
        while (new_val > 0 && new_val % 2 == 0)
        {
            callA++;
            new_val /= 2;
        }
              
        while (new_val > 0 && new_val % 3 == 0)
        {
            callB++;
            new_val /= 3;
        }
        
        while (new_val > 0 && new_val % 5 == 0)
        {
            callC++;
            new_val /= 5;
        }
		
    }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

