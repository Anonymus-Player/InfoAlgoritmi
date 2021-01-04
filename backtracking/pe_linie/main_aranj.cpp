#include <iostream>

int st[100], n, i, k, p;
int st_perm[100], st_int_perm[100], n_perm, i_perm, k_perm;

void init_perm()
{
    st_perm[k_perm] = 0;
}

int succesor_perm()
{
    if(st_perm[k_perm] < n_perm)
    {
        st_perm[k_perm]++;
        return 1;
    }
    else
        return 0;
}

int valid_perm()
{
    for(i_perm = 1; i_perm <= k_perm - 1; i_perm++)
        if(st_perm[k_perm] == st_perm[i_perm])
            return 0;
    return 1;
}

int solutie_perm()
{
    return k_perm == n_perm;
}

void afisare_perm()
{
    for(i_perm = 1; i_perm <= k_perm; i_perm++)
        std::cout << st_int_perm[st_perm[i_perm]] << " ";
    std::cout << "\n"; 
}

void back_perm()
{
    int as_perm;
    k_perm = 1;
    init_perm();
    while(k_perm > 0)
    {
        do{}while((as_perm = succesor_perm()) && !valid_perm());
        if(as_perm)
        {
            if(solutie_perm())
            {
                afisare_perm();
            }
            else
            {
                k_perm++;
                init_perm();
            }
        }
        else
            k_perm--;
    }
}

/*void citire_st_perm()
{
    std::cin >> n_perm;
    for(i_perm = 1; i_perm <= n_perm; i_perm++)
        std::cin >> st_int_perm[i_perm];
}*/

/*int main()
{
    citire_st_perm();
    back_perm();
    return 0;
}*/

void init()
{
    st[k] = -1;
}

int succesor()
{
   	if(st[k] < 1)
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
   	return k == n;
}

int solutie_comb()
{
	int t = 0;
    for (i = 1; i <= k; i++)
    {
        if(st[i] == 1)
            t++;
    }
	return t == p;
}

void permutare()
{
    n_perm = 0;
	for(i = 1; i <= k; i++)
		if(st[i] == 1)
            st_int_perm[++n_perm] = i;
    if(n_perm)
        back_perm();
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
				if(solutie_comb())
					permutare();
	    	}
	    	else
	    	{
				k++;
				init();
	    	}
		}
		else
		{
	   		k--;
		}
   }
}

int main()
{
   	std::cin >> n;
    std::cin >> p;
   	back();
   	return 0;
}