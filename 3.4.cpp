#include <iostream>
using namespace std;

template <typename Type>
class CVector {
private:
    Type* m_pVect,        
        m_nCount,         
        m_nMax,           
        m_nDelta;       
    void Init(int delta);  
    void Resize();         

public:
    CVector(int delta = 10);  
    void Insert(Type elem);   
    void Print();
};
template <typename Type>
void CVector<Type>::Init(int delta) {
    m_pVect = NULL;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}
template <typename Type>
void CVector<Type>::Resize() {
    m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
    m_nMax += m_nDelta;
}
template <typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
}
template <typename Type>
void CVector<Type>::Insert(Type elem) {
    if (m_nCount == m_nMax)      
        Resize();                  
    m_pVect[m_nCount++] = elem;  
}
template <typename Type>
void CVector<Type>::Print() {
    cout << "Vector: " << endl;
    for (int* i = m_pVect; i < m_pVect + m_nCount; i++) cout << *i << " ";
    cout << "Conteo: " << m_nCount << " , Max: " << m_nMax << endl;
}
int main() {
    return 0;
}