#include <iostream>

class CVector {
private:
    int* m_pVector,
        m_nCount,
        m_nMax,
        m_nDelta;
    void Init(int delta);
    void resize();

public:
    CVector(int delta = 10);
    void insert(int element);
};

int main()
{
    CVector work;
    for (int i = 0; i < 10; i++)
        work.insert(1);
    work.insert(2);
    work.insert(3);
    return 0;
}

void CVector::Init(int delta)
{
    m_nCount = 0;
    m_nMax = 0;
    m_pVector = NULL;
    m_nDelta = delta;
}

void CVector::resize()
{
    m_pVector = (int*)realloc(m_pVector, sizeof(int) * (m_nMax + m_nDelta));
    m_nMax += m_nDelta;
}


CVector::CVector(int delta)
{
    Init(delta);
}

void CVector::insert(int element)
{
    if (m_nCount == m_nMax)
        resize();
    m_pVector[m_nCount++] = element;
}
