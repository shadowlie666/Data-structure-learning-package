/*
��Ϊ���ֲ��Ҷ���ı������˳��洢�������ͨ���ٶ�������ǰ��ؼ��ִ�С��������

���ҹ���������ȡ��������� A[0] ~ A[n - 1] ���е�Ԫ�� A[mid] ��mid = (0 + n -1) / 2�� �Ĺؼ���ͬ����ֵ K �Ƚϣ������ɹ����� K ��С����� ʣ�����벿�ֽ���ͬ��

�������� �� �ϴ������ʣ����Ұ벿�ֽ���ͬ���Ĳ���
*/ 

int Binsch(struct ElemType A[], int low, int high, KeyType K)//�ݹ鷨
{//�� A[low] ~ A[hight]������в��ң�low��hight��ֵ�ֱ�Ϊ 0 �� n-1
    if (low <= hight)
    {
        int mid = (low + high) / 2; //���е�Ԫ���±�
        if (K == A[mid].key)
            return mid;
        else if (K < A[mid].key)
            return Binsch(A, low, mid - 1, K);
        else 
            return Binsch(A, mid + 1, high, K);
    }
    else
        return -1; //����ʧ��
}
 
int Binsch1(struct ElemType A[], int low, int high, KeyType K)//�ǵݹ鷨
{//�� A[low] ~ A[hight]������в��ң�low��hight��ֵ�ֱ�Ϊ 0 �� n-1
    while (low <= high)
    {
        int mid = (low + high) / 2; //���е�Ԫ���±�
        if (K == A[mid].key)
            return mid;
        else if (K < A[mid].key)
            high = mid - 1;
        else 
            low = mid + 1;
    }
        return -1; //ִ����������䣬˵������23�е�returnû��ִ�У������ʧ��
}
