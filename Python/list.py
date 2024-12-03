#!/usr/bin/env python3
from typing import List
def chunk_list(lst: list, chunk_size: int, lst_size=None) -> List[list]:
    """
    Given a list and a size of chunk, it separates the list into a list of
    sublists of the original list.

    The `lst_size` is an optional argument that can be given in the case the
    length of the original list was already computed in cases where the
    `chunk_size` is a factor of the length of the list. So to avoid
    recomputating the length.
    """
    if lst_size is None:
        lst_size = len(lst)
    return [lst[i:i + chunk_size]
            for i in range(0, lst_size, chunk_size)]

if __name__ == '__main__':
    lst = [1,2,3,4,5,6,7,8,9]
    print(chunk_list(lst, 3))