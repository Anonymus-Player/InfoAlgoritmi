#include <iostream>

int st[10], i, n, k, max;

void init()
{
   st[k] = 0;
}

int succesor()
{
    max = 0;
    for(i = 1; i <= k; i++)
		if(max < st[i])
	    	max = st[i];
    if(st[k] < max)
    {
		st[k]++;
		return 1;
	}
	else
		return 0;
}

int valid()
{
    for(i = 1; i <= k - 1; i++)
		if(st[k] == st[i])
	    	return 0;
    return 1;
}

int solutie()
{
    return k == n;
}

void tipar()
{
    max = 0;
    for(i = 1; i <= k; i++)
		if(max < st[i])
	    	max = st[i];
    for(i = 1; i <= max; i++)
    {
		std::cout << "{ ";
		for(int j = 1; j <= k; j++)
	    	if(st[j] == i)
				std::cout << j << " ";
		std::cout << "}  ";
    }
    std::cout << std::endl;
}

void back()
{
    int as;
    k = 1;
    init();
    while(k > 0)
    {
		do{}while((as = succesor()) && !valid());
		if(as)
		{
	    	if(solutie())
				tipar();
	    	else
	    	{
			k++;
			init();
	    	}
		}
		else
	    	k--;
	}
}

int main()
{
    std::cin >> n;
    back();
    return 0;
}
