function a = heapSort(a)
sz = size(a, 2);
h = stem(a, 'ydatasource', 'a')
  a = build(a);
  refreshdata([gcf], 'caller');
  drawnow;
  for i = sz : -1 : 2
      temp = a(i);
      a(i) = a(1);
      a(1) = temp;
      a = heapify(a, i - 1, 1);
      refreshdata([gcf], 'caller');
      drawnow;
  end;
end;

function a = heapify (a, size, node)
 max = -1;
 leftChild = 2 * node;
 rightChild = 2 * node + 1;
  if (node <= (size) / 2)
     if (rightChild <= size && a(rightChild) > a(leftChild))
         max = rightChild;
     else
         max = leftChild;
     end;
     
     if (a(node) < a(max))
         temp = a(node);
         a(node) = a(max);
         a(max)= temp;
         a = heapify(a, size, max);
     
     end;
 end;
end
 
 function a = build (a)
     n = size(a, 2);
     for i = floor(n / 2): -1 : 1
         a = heapify(a, n, i);
     end;
 end 
     
 