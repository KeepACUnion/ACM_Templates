// player = 1 表示轮到己方， player = 0 表示轮到对方
// cur_node 表示当前局面(结点)
maxmin(player, cur_node, alpha, beta)
{
	if 达到终结局面
		return 该局面结点的估价值 f
	end
	if player == 1 // 轮到己方走
		for 每一种走法 do
			new_node = get_next(cur_node) // 遍历当前局面 cur_node 的所有子局面
			val = maxmin(player^1, new_node, alpha, beta); // 把新产生的局面交给对方，对方返回一个新局面的估价值
		    if val > alpha
				alpha = val;
			end
			if alpha > beta
				return alpha;
			end
		end
		return alpha;
	else // 轮到对方走
		for 每一种走法 do
			new_node = get_next(cur_node) // 遍历当前局面 cur_node 的所有子局面
			val = maxmin(player^1, new_node, alpha, beta); // 把新产生的局面交给对方，对方返回一个新局面的估价值
		    if val < beta 
				beta = val;
			end
			if alpha > beta
				return beta;
			end
		end
		return beta;
	end
}
