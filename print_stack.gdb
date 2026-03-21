define print_stack
set $tmp = $arg0
if ($tmp == 0)
    printf "Stack is empty\n"
else
    while ($tmp != 0)
        printf "%d -> ", $tmp->value
        set $tmp = $tmp->next
    end
    printf "NULL\n"
end
