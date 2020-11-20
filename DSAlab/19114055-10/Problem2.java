/*
Masthead - 
Owner - Mayank Meena 
Enroll no. 19114055
Code Editor - VSCode 2020(1.40.1)
Terminal - Ubuntu Terminal 20.04
Shell - git bash

Contact - 
Website - https://mayankmeena.netlify.app/
Email - mayank_m@cs.iitr.ac.in

Social -
GitHub - https://github.com/maayami
YouTube - https://www.youtube.com/channel/UCwcdyxP6uk5zso-L4lY4Y8g?view_as=subscriber
Twitter - https://twitter.com/Meina_Mk
*/

import java.util.Scanner;

class Problem2 {

  private int minChildren;
  private static int numOfSplits;
  private static int numOfMerges;
  // Creating Node having keys and child array
  public class Node {
    int num;
    int keyArray[] = new int[2 * minChildren - 1];
    Node child_array[] = new Node[2 * minChildren];
    boolean isLeaf = true;

    public int FindKey(int k) {
      for (int i = 0; i < this.num; i++) {
        if (this.keyArray[i] == k) {
          return i;
        }
      }
      return -1;
    };
  }

  public Problem2(int t) {
    minChildren = t;
    root = new Node();
    root.num = 0;
    root.isLeaf = true;
  }

  private Node root;

  // split
  
   private Node SearchKey(Node x, int key) {
    int i = 0;
    if (x == null)
      return x;
    for (i = 0; i < x.num; i++) {
      if (key < x.keyArray[i]) {
        break;
      }
      if (key == x.keyArray[i]) {
        return x;
      }
    }
    if (x.isLeaf) {
      return null;
    } else {
      return SearchKey(x.child_array[i], key);
    }
  }

  
  private void RemoveKey(Node x, int key) {
    int index_of_key = x.FindKey(key);
    if (index_of_key != -1) {
      if (x.isLeaf) {
        int i = 0;
        for (i = 0; i < x.num && x.keyArray[i] != key; i++) {
        }
        ;
        for (; i < x.num; i++) {
          if (i != 2 * minChildren - 2) {
            x.keyArray[i] = x.keyArray[i + 1];
          }
        }
        x.num--;
        
        return;
      }
      if (!x.isLeaf) {
        Node predecessor = x.child_array[index_of_key];
        int predecessorKey = 0;
        if (predecessor.num >= minChildren) {
          for (;;) {
            if (predecessor.isLeaf) {
              predecessorKey = predecessor.keyArray[predecessor.num - 1];
              break;
            } else {
              predecessor = predecessor.child_array[predecessor.num];
            }
          }
          
          RemoveKey(predecessor, predecessorKey);
          x.keyArray[index_of_key] = predecessorKey;
          return;
        }

        Node nextNode = x.child_array[index_of_key + 1];
        
        if (nextNode.num >= minChildren) {
          int nextKey = nextNode.keyArray[0];
          if (!nextNode.isLeaf) {
            nextNode = nextNode.child_array[0];
            for (;;) {
              if (nextNode.isLeaf) {
                nextKey = nextNode.keyArray[nextNode.num - 1];
                
                break;
              } else {
                nextNode = nextNode.child_array[nextNode.num];
                
              }
            }
            numOfMerges++;
          }
          
          RemoveKey(nextNode, nextKey);
          x.keyArray[index_of_key] = nextKey;
          return;
        }
        
        int temp = predecessor.num + 1;
        predecessor.keyArray[predecessor.num++] = x.keyArray[index_of_key];
        for (int i = 0, j = predecessor.num; i < nextNode.num; i++) {
          predecessor.keyArray[j++] = nextNode.keyArray[i];
          predecessor.num++;
        }
        for (int i = 0; i < nextNode.num + 1; i++) {
          predecessor.child_array[temp++] = nextNode.child_array[i];
        }

        x.child_array[index_of_key] = predecessor;
        for (int i = index_of_key; i < x.num; i++) {
          if (i != 2 * minChildren - 2) {
            x.keyArray[i] = x.keyArray[i + 1];
          }
        }
        
        for (int i = index_of_key + 1; i < x.num + 1; i++) {
          if (i != 2 * minChildren - 1) {
            x.child_array[i] = x.child_array[i + 1];
          }
        }
        numOfMerges++;
        x.num--;
        if (x.num == 0) {
          if (x == root) {
            root = x.child_array[0];
          }
          x = x.child_array[0];
        }
        
        RemoveKey(predecessor, key);
        return;
      }
    } else {
    
      for (index_of_key = 0; index_of_key < x.num; index_of_key++) {
        if (x.keyArray[index_of_key] > key) {
          break;
        }
      }
      Node tmp = x.child_array[index_of_key];
      if (tmp.num >= minChildren) {
        RemoveKey(tmp, key);
        return;
      }
      if (true) {
          
        Node nb = null;
        int divider = -1;
        // borrow from right immediate neighbour
        if (index_of_key != x.num && x.child_array[index_of_key + 1].num >= minChildren) {
          divider = x.keyArray[index_of_key];
          nb = x.child_array[index_of_key + 1];
          x.keyArray[index_of_key] = nb.keyArray[0];
          tmp.keyArray[tmp.num++] = divider;
          tmp.child_array[tmp.num] = nb.child_array[0];
          for (int i = 1; i < nb.num; i++) {
            nb.keyArray[i - 1] = nb.keyArray[i];
          }
          for (int i = 1; i <= nb.num; i++) {
            nb.child_array[i - 1] = nb.child_array[i];
          }
          
          nb.num--;
          RemoveKey(tmp, key);
          return;
        } 
        // borrow from left immediate neighbour
        else if (index_of_key != 0 && x.child_array[index_of_key - 1].num >= minChildren) {
          divider = x.keyArray[index_of_key - 1];
          nb = x.child_array[index_of_key - 1];
          x.keyArray[index_of_key - 1] = nb.keyArray[nb.num - 1];
          Node child_array = nb.child_array[nb.num];
          nb.num--;
          for (int i = tmp.num; i > 0; i--) {
            tmp.keyArray[i] = tmp.keyArray[i - 1];
          }
          tmp.keyArray[0] = divider;
          for (int i = tmp.num + 1; i > 0; i--) {
            tmp.child_array[i] = tmp.child_array[i - 1];
          }
          tmp.child_array[0] = child_array;
          tmp.num++;
          RemoveKey(tmp, key);
          return;
        } else {
          Node lt = null;
          Node rt = null;
          boolean last = false;
          if (index_of_key != x.num) {
            divider = x.keyArray[index_of_key];
            lt = x.child_array[index_of_key];
            rt = x.child_array[index_of_key + 1];
          } else {
            
            divider = x.keyArray[index_of_key - 1];
            // index_of_key is equal to x.num 
            rt = x.child_array[index_of_key];
            lt = x.child_array[index_of_key - 1];
            last = true;
            index_of_key--;
          }
          for (int i = index_of_key; i < x.num - 1; i++) {
            x.keyArray[i] = x.keyArray[i + 1];
          }
          for (int i = index_of_key + 1; i < x.num; i++) {
            x.child_array[i] = x.child_array[i + 1];
          }
          x.num--;
          lt.keyArray[lt.num++] = divider;

          for (int i = 0, j = lt.num; i < rt.num + 1; i++, j++) {
            if (i < rt.num) {
              lt.keyArray[j] = rt.keyArray[i];
            }
            lt.child_array[j] = rt.child_array[i];
          }
          numOfMerges++;
          lt.num += rt.num;
          if (x.num == 0) {
            if (x == root) {
              root = x.child_array[0];
            }
            x = x.child_array[0];
            
          }
          
          RemoveKey(lt, key);
          return;
        }
      }
    }
  }

  public void Remove_element(int key) {
    Node x = SearchKey(root, key);
    if (x == null) {
      return;
    }
    RemoveKey(root, key);
  }
  
  private void split(Node x, int index_of_key, Node y) {
    Node z = new Node();
    z.isLeaf = y.isLeaf;
    z.num = minChildren - 1;
    for (int j = 0; j < minChildren - 1; j++) {
      z.keyArray[j] = y.keyArray[j + minChildren];
    }
    if (!y.isLeaf) {
      for (int j = 0; j < minChildren; j++) {
        z.child_array[j] = y.child_array[j + minChildren];
      }
    }
    y.num = minChildren- 1;
    for (int j = x.num; j >= index_of_key + 1; j--) {
      x.child_array[j + 1] = x.child_array[j];
    }
    x.child_array[index_of_key + 1] = z;

    for (int j = x.num - 1; j >= index_of_key; j--) {
      x.keyArray[j + 1] = x.keyArray[j];
    }
    x.keyArray[index_of_key] = y.keyArray[minChildren- 1];
    x.num = x.num + 1;
  }

  // insert keyArray
  public void insert(final int keyArray) {
    Node r = root;
    if (r.num == 2 * minChildren- 1) {
      Node s = new Node();
      root = s;
      s.isLeaf = false;
      s.num = 0;
      s.child_array[0] = r;
      numOfSplits++;
      split(s, 0, r);
      _insert(s, keyArray);
    } else {
      _insert(r, keyArray);
    }
  }

  // insert node
  final private void _insert(Node x, int k) {

    if (x.isLeaf) {
      int i = 0;
      for (i = x.num - 1; i >= 0 && k < x.keyArray[i]; i--) {
        x.keyArray[i + 1] = x.keyArray[i];
      }
      x.keyArray[i + 1] = k;
      x.num = x.num + 1;
    } else {
      int i = 0;
      for (i = x.num - 1; i >= 0 && k < x.keyArray[i]; i--) {
      }
      ;
      i++;
      Node tmp = x.child_array[i];
      if (tmp.num == 2 * minChildren - 1) {
        numOfSplits++;
        split(x, i, tmp);
        if (k > x.keyArray[i]) {
          i++;
        }
      }
      _insert(x.child_array[i], k);
    }

  }

  public void Inorder() {
    Inorder(root);
  }

  private void Inorder(Node x) {
    if (x == null){
        return;
    };
    int i;
    for (i = 0; i < x.num; i++) {
        if(!x.isLeaf){
            Inorder(x.child_array[i]);
        }
        System.out.print(x.keyArray[i] + " ");
    }
    if (!x.isLeaf) {
      Inorder(x.child_array[i]);
    }
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int number_of_queries,minimum_num_of_children;
    number_of_queries = input.nextInt();
    minimum_num_of_children = input.nextInt();
    // creating B-Tree
    Problem2 b = new Problem2(minimum_num_of_children);
    
    char query;
    int data;
    for(int i=1;i<=number_of_queries;i++){
        query = input.next().charAt(0);
        data = input.nextInt();
        if(query == 'i')
            b.insert(data);
        else if(query == 'd')
            b.Remove_element(data);
    }
    
    System.out.println(numOfSplits);
    System.out.println(numOfMerges);
    b.Inorder();
    
    input.close();
  }
}
