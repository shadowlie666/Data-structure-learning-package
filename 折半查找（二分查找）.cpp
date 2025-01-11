/*
作为二分查找对象的表必须是顺序存储的有序表，通常假定有序表是按关键字从小到大有序。

查找过程是首先取整个有序表 A[0] ~ A[n - 1] 的中点元素 A[mid] （mid = (0 + n -1) / 2） 的关键字同给定值 K 比较，相等则成功，若 K 较小，则对 剩余的左半部分进行同样

操作，若 Ｋ 较大，则对其剩余的右半部分进行同样的操作
*/ 

int Binsch(struct ElemType A[], int low, int high, KeyType K)//递归法
{//在 A[low] ~ A[hight]区间进行查找，low、hight初值分别为 0 和 n-1
    if (low <= hight)
    {
        int mid = (low + high) / 2; //求中点元素下标
        if (K == A[mid].key)
            return mid;
        else if (K < A[mid].key)
            return Binsch(A, low, mid - 1, K);
        else 
            return Binsch(A, mid + 1, high, K);
    }
    else
        return -1; //查找失败
}
 
int Binsch1(struct ElemType A[], int low, int high, KeyType K)//非递归法
{//在 A[low] ~ A[hight]区间进行查找，low、hight初值分别为 0 和 n-1
    while (low <= high)
    {
        int mid = (low + high) / 2; //求中点元素下标
        if (K == A[mid].key)
            return mid;
        else if (K < A[mid].key)
            high = mid - 1;
        else 
            low = mid + 1;
    }
        return -1; //执行了这行语句，说明上面23行的return没有执行，则查找失败
}
