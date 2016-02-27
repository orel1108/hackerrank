class Matrix
{
   public:
    vector< vector<int> > a;
};

Matrix operator+(const Matrix & i_left, const Matrix & i_right)
{
    const size_t num_rows = i_left.a.size();
    const size_t num_cols = i_left.a[0].size();
    Matrix res;
    for (size_t row_num = 0U; row_num < num_rows; ++row_num)
    {
        vector< int > row;
        for (size_t col_num = 0U; col_num < num_cols; ++col_num)
            row.push_back(i_left.a[row_num][col_num] + i_right.a[row_num][col_num]);
        res.a.push_back(row);   
    }
    return res;
}

