define print_index
set $tmp = $arg0
if ($tmp == 0)
    printf "Stack is empty\n"
else
    while ($tmp != 0)
        printf "%d -> ", $tmp->index
        set $tmp = $tmp->next
    end
    printf "NULL\n"
end
