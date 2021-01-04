#include <iostream>
#include <memory.h>

int st[100], st_cif[100], i, n, k, t;

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

int solutie_cif()
{
    int cif = 0;
    if(st_cif[st[1]] == 0 && t != 1)
        return 0;
    for(i = 1; i <= k; i++)
    {
        cif *= 10;
        cif += st_cif[st[i]];
    }
    return cif % 2 == 0;
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
            {
                if(solutie_cif())
				    tipar();
            }  
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
    std::cin >> t;
    n = 0;
    for (i = 0; i < 10; i++)
		st_cif[++n] = i;
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
