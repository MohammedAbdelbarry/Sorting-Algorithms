function a =heapSort(a,size)
h = stem(a,'ydatasource','a')
  a = build(a,size);
  refreshdata([gcf],'caller');
  drawnow;
  for i = size;-1;2
      temp = a(size - i);
      a(size - i) = a(1);
      a(1) = temp;
      a = heapify(a,size-i,1);
      refreshdata([gcf],'caller');
      drawnow;
  end;
end
 
function a= heapify (a,size,node)
  max =-1;
 leftChild = 2*node ;
 rightChild = 2*node+1;
 if (node <=(size)/2)
     if (rightChild<=size && a(rightChild) > a(leftChild))
          max=rightChild;
     else
         max= leftChild;
     end;
     
     if (a(node) < a(max))
        temp = a(node);
        a(node)= a(max);
         a(max)=temp;
      a=heapify(a,size,max);
     end;
 end;
end
 
 function a= build (a,size)
     for i = (size/2):1
         a=heapify(a,size,i);
     end;
 end