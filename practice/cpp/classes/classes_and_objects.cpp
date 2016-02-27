class Student
{
    public:
        void Input()
        {
            for (int i = 0; i < 5; ++i)
            {
                cin >> score[i];
            }
        }
        
        int CalculateTotalScore() const 
        {
            return score[0] + score[1] + score[2] + score[3] + score[4];
        }
    private:
        int score[5];
};
