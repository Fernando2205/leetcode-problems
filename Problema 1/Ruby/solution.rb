class ListNode
    attr_accessor :val, :next
  
    def initialize(val = 0, _next = nil)
      @val = val
      @next = _next
    end
  end
  
  class Solution
    def remove_nth_from_end(head, n)
      raise 'n debe ser al menos 1' if n < 1
  
      aux = ListNode.new(0)
      aux.next = head
      first = aux
      second = aux
  
      (n + 1).times do
        raise 'n es mayor que el número de nodos en la lista' if first.nil?
        first = first.next
      end
  
      while first
        first = first.next
        second = second.next
      end
  
      second.next = second.next.next
  
      aux.next
    end
  
    def list_to_listnode(lst)
      raise 'El número de nodos en la lista debe estar entre 1 y 30' unless lst.length.between?(1, 30)
      lst.each { |val| raise 'Los valores de los nodos deben estar entre 0 y 100' unless (0..100).include?(val) }
  
      aux = ListNode.new(0)
      current = aux
      lst.each do |val|
        current.next = ListNode.new(val)
        current = current.next
      end
      aux.next
    end
  
    def listnode_to_list(node)
      lst = []
      while node
        lst << node.val
        node = node.next
      end
      lst
    end
  end
  