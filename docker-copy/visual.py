import graphviz
import random

def parse_line(line):
    # 移除行首尾的空格和"[]"
    line = line.strip().strip('[]')

    # 分割行以提取各个部分
    parts = line.split(' ')

    # 初始化layer, name, val
    source,layer, name, val = "", 0, "", ""

    # 解析layer, name, val
    for i, part in enumerate(parts):
        if part == "source:":
            source = parts[i+1].strip('()')
        elif part == "layer:":
            layer = int(parts[i + 1].strip('()'))
        elif part == "name:":
            name = parts[i + 1].strip('()')
        elif part == "val:" and i + 1 < len(parts):
            val = parts[i + 1]

    # 确保当val不存在时，使用空字符串
    val = "" if val is None else val

    return source,layer, name, val










def build_graph(filename):
    graph = graphviz.Digraph('AST', filename='ast.gv')
    last_nodes = {0: None}  # 存储上一层的节点ID

    with open(filename, 'r') as file:
        for line in file:
            source,layer, name, val = parse_line(line)
            # 创建节点的唯一标识符ID
            postfix = random.random()
            node_id = f'{name}_{layer}_{postfix}'
            # 创建节点标签，总是包括name，如果val存在则显示Val: val
            node_label = f'Name:{name}' + (f'\nVal: {val}' if val else '') +f'\nSource: {source}'
            # 创建图形的节点
            graph.node(node_id, label=node_label)
            # 找到当前节点的父节点并建立连接
            parent_layer = layer - 1
            if parent_layer in last_nodes:
                parent_id = last_nodes[parent_layer]
                if parent_id:  # 如果父节点存在，创建边
                    graph.edge(parent_id, node_id)
            # 更新当前层的最后一个节点
            last_nodes[layer] = node_id

    return graph








graph = build_graph('ast_output.txt')
graph.render('ast_output', format='png', view=False)
