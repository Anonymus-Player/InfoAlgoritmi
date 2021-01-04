#include <iostream>
#include <memory.h>

int st[10], st_cif[10], i, n, k, t;

void init()
{
    st[k] = 0;
}

int succesor()
{
    if(st[k] < n)
    {
		st[k]++;
		return 1;
    }
    else
		return 0;
}

int valid()
{
    return 1;
}

int solutie()
{
    return k == t;
}

void tipar()
{
    for(i = 1; i <= k; i++)
    {
		std::cout << st_cif[st[i]];
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

void vec()
{
    int p, v[10];
	memset(v, 0, sizeof(v));
    std::cin >> p;
    std::cin >> t;
    n = 0;
    while(p)
    {
		v[p % 10]++;
		p /= 10;
    }
    for (i = 0; i < 10; i++)
	{
		if(v[i])
		{
			st_cif[++n] = i;
		}
	}
	if(st_cif[1] == 0)
	{
		int z = st_cif[1];
		st_cif[1] = st_cif[2];
		st_cif[2] = z;
	}
}

int main()
{
    vec();
    back();
    return 0;
}
