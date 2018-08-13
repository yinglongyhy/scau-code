package com.scau;

public class RBTree<T extends Comparable<T>> {

    private RBNode<T> root; // 根节点
    final private static boolean RED = true; // 定义红色为true
    final private static boolean BLACK = false; // 定义黑色为false

    //内部类：树的节点
    private class RBNode<T extends Comparable<T>> {
        private boolean color; // true为红， false为黑
        private T data; // 数据域
        private RBNode<T> lchild; // 左孩子
        private RBNode<T> rchild; // 右孩子
        private RBNode<T> father; // 父节点

        public RBNode(T data) {
            this.color = RED; // 默认新节点为红色
            this.data = data;
            this.lchild = null;
            this.rchild = null;
            this.father = null;
        }
    }

    public RBTree() {
        this.root = null;
    }

    public RBNode<T> getRoot() {
        return this.root;
    }

    private boolean isRed(RBNode<T> node) {
        return node != null && node.color != BLACK;
    }

    private boolean isBlack(RBNode<T> node) {
        return node == null || node.color == BLACK;
    }

    private void setRed(RBNode<T> node) {
        if (node != null) node.color = RED;
    }

    private void setBlack(RBNode<T> node) {
        if (node != null) node.color = BLACK;
    }

    private RBNode<T> getFather(RBNode<T> node) {
        return node == null || node.father == null ? null : node.father;
    }

    private RBNode<T> getUncle(RBNode<T> node) {
        RBNode<T> father = getFather(node);
        RBNode<T> grandfather = getFather(father);
        if (father == null || grandfather == null) return null;
        return grandfather.lchild == father ? grandfather.rchild : grandfather.lchild;
    }

    private void liftRotate(RBNode<T> node) {
        /*
        1 设newPivot保存node的右子节点
        2 node的右子节点指向newPivot的左子节点，newPivot的左子节点（若不为空）的父节点指向node
        3 newPivot的左子节点指向node
        4 newPivot的父节点指向node的父节点，node的父节点的左/右子节点指向newPivot
        5 node的父节点指向newPivot
        6 判断newPivot的父节点是否为null，是 设newPivot为根节点
         */
        RBNode<T> newPivot = node.rchild;
        node.rchild = newPivot.lchild;
        if (node.lchild != null) newPivot.lchild.father = node;
        newPivot.lchild = node;
        newPivot.father = node.father;
//        if (node.father == null) System.out.println("father is null");
        if (node.father != null) {
            if ((node.father.lchild == node)) {
                node.father.lchild = newPivot;
            } else {
                node.father.rchild = newPivot;
            }
        } else {
            this.root = newPivot;
        }
        node.father = newPivot;
    }

    private void rightRotate(RBNode<T> node) {
        /*
        1 设newPivot保存node的左子节点
        2 node的左子节点指向newPivot的右子节点，newPivot的右子节点（若不为空）的父节点指向node
        3 newPivot的右子节点指向node
        4 newPivot的父节点指向node的父节点，node的父节点的左/右子节点指向newPivot
        5 node的父节点指向newPivot
        6 判断newPivot的父节点是否为null，是 设newPivot为根节点
         */
        RBNode<T> newPivot = node.lchild;
        node.lchild = newPivot.rchild;
        if (newPivot.rchild != null) newPivot.rchild.father = node;
        newPivot.rchild = node;
        newPivot.father = node.father;
        if (node.father != null) {
            if ((node.father.lchild == node)) {
                node.father.lchild = newPivot;
            } else {
                node.father.rchild = newPivot;
            }
        } else {
            this.root = newPivot;
        }
        node.father = newPivot;
    }

    public void addNode(T data) {
        RBNode<T> newNode = new RBNode<>(data);
        RBNode<T> compareNode = this.root;
        RBNode<T> compareNodePre = compareNode;
        while (compareNode != null) {
            compareNodePre = compareNode;
            compareNode = compareNode.data.compareTo(newNode.data) > 0 ? compareNode.lchild : compareNode.rchild;
        }
        if (compareNodePre == null) this.root = newNode;
        else {
            if (compareNodePre.data.compareTo(newNode.data) > 0) { // newNode 小，插在compareNodePro的左子节点
                compareNodePre.lchild = newNode;
            } else {
                compareNodePre.rchild = newNode;
            }
            newNode.father = compareNodePre;
        }

        //插入完毕，下面插入修正
        addFixUp(newNode);
    }

    private void addFixUp(RBNode<T> node) {
        RBNode<T> father = getFather(node);
        RBNode<T> uncle = getUncle(node);
        if (isRed(father) && isRed(uncle)) { // 第一种情况：父节点与叔叔节点为红，把父节点和叔叔节点设为黑色，祖父节点设为红色，把当前节点定位到其祖父节点
            setBlack(father);
            setBlack(uncle);
            setRed(getFather(father));
            node = getFather(father);
        }

        father = getFather(node);
        uncle = getUncle(node);
        while (isRed(father) && isBlack(uncle)) { // 第二第三种情况：父节点为红，叔叔节点为黑
            if (father == getFather(father).lchild) { // 父节点是祖父节点的左孩子
                if (node == father.rchild) { // 情况二：当前节点是父节点的右孩子
                    node = father; // 以父节点为当前节点
                    liftRotate(node); // 当前节点左旋
                } else { // 情况三：当前节点是父节点的左孩子
                    setBlack(father); // 父节点涂黑
                    node = getFather(father); // 当前节点定位到祖父节点
                    setRed(node); // 祖父节点涂红
                    rightRotate(node); // 右旋
                }
            } else { // 父节点是祖父节点的右孩子
                if (node == father.lchild) { // 情况二：当前节点是父节点的左孩子
                    node = father; // 以父节点为当前节点
                    rightRotate(node); // 右旋
                } else { // 情况三：当前节点是父节点的右孩子
                    setBlack(father); // 父节点涂黑
                    node = getFather(father); // 当前节点定位到祖父节点
                    setRed(node); // 祖父节点涂红
                    liftRotate(node); // 当前节点左旋
                }
            }
//            this.preTraversal(root);
//            System.out.println();

            // 重新定位父节点和叔叔节点
            father = getFather(node);
            uncle = getUncle(node);
        }

        setBlack(root); // 将根节点涂黑
    }

    private RBNode<T> searchNode(T data) {
        RBNode<T> node = root;
        while (node != null) {
            if (node.data.compareTo(data) > 0) { // 要查找的data小
                node = node.lchild;
            } else if (node.data.compareTo(data) < 0) { // 要查找的data大
                node = node.rchild;
            } else { // 找到，返回对象
                return node;
            }
        }
        //没找到
        return null;
    }

    public void removeNode(T data) {
        RBNode<T> node = searchNode(data);
        if (node == null) {
            return;
        }

        RBNode<T> father = getFather(node);
        if (node.lchild == null && node.rchild == null) { // 情况一：删除节点为叶子
            if (father.lchild == node) {
                father.lchild = null;
            } else {
                father.rchild = null;
            }
            node.father = null;

        } else if (node.lchild == null || node.rchild == null) { // 情况二：删除节点有一个孩子
            // 用删除节点的孩子替代删除节点
            if (node.lchild == null) {
                if (father.lchild == node) {
                    father.lchild = node.rchild;
                } else {
                    father.rchild = node.rchild;
                }
                node.rchild.father = father;
                node.rchild = null;
            } else {
                if (father.lchild == node) {
                    father.lchild = node.lchild;
                } else {
                    father.rchild = node.lchild;
                }
                node.lchild.father = father;
                node.lchild = null;
            }
            node.father = null;

        } else { // 情况三：删除节点有两个孩子
            // 找到删除节点的直接前驱
            RBNode<T> preNode = node.lchild;
            while (preNode.rchild != null) {
                preNode = preNode.rchild;
            }
            // 保存直接前驱父节点和子节点的信息
            RBNode<T> prefather = getFather(preNode);
            RBNode<T> prechild = preNode.lchild;
            // 直接前驱替换删除节点
            preNode.father = father;
            preNode.rchild = node.rchild;
            boolean color = preNode.color;
            preNode.color = node.color;
            node.rchild.father = preNode;

            if (preNode != node.lchild) {
                preNode.lchild = node.lchild;
                node.lchild.father = preNode;
            }
            if (father != null) {
                if (father.lchild == node) {
                    father.lchild = preNode;
                } else {
                    father.rchild = preNode;
                }
            }
            if (node == root) {
                root = preNode;
            }
            //连接直接前驱的父节点和子节点
            if (prefather.lchild == preNode) {
                prefather.lchild = prechild;
            }else{
                prefather.rchild = prechild;
            }
            if (prechild != null) {
                prechild.father = prefather;
            }
            // 删除修复
            if (color == BLACK) { // 如果移走的前驱是黑色，重整红黑树
                removeFixUp(prechild, prefather);
            }
        }
    }

    private void removeFixUp(RBNode<T> node, RBNode<T> father) {
        RBNode<T> brother;
        while (isBlack(node) && node != root) {
            if (node == father.lchild) { // node是左子节点
                brother = father.rchild; // brother是右子节点
                if (isRed(brother)) { // 情况一：brother为红色
                    /*
                    将父节点涂红，将兄弟节点涂黑，然后将当前节点的父节点作为支点左旋
                     */
                    setRed(father);
                    setBlack(brother);
                    liftRotate(father);
                }

                if (isBlack(brother)) { // 情况二、三、四：brother为黑色
                    if (isBlack(brother.lchild) && isBlack(brother.rchild)) { // 情况二：兄弟节点的两个子节点均为黑色
                        /*
                        将兄弟节点涂红，将当前节点指向其父节点，将其父节点指向当前节点的祖父节点
                         */
                        setRed(brother);
                        node = father;
                        father = getFather(node);
                    } else { // 情况三、四
                        if (isRed(brother.lchild) && isBlack(brother.rchild)) { // 情况三：兄弟节点的左子节点是红色，右子节点时黑色的
                            /*
                            把当前节点的兄弟节点涂红，把兄弟节点的左子节点涂黑，然后以兄弟节点作为支点做右旋操作
                             */
                            setRed(brother);
                            setBlack(brother.lchild);
                            rightRotate(brother);
                        }

                        // 情况四：兄弟节点的右子节点是红色，左子节点任意颜色
                        /*
                        把兄弟节点涂成父节点的颜色，再把父节点涂黑，把兄弟节点的右子节点涂黑，然后以当前节点的父节点为支点做左旋操作
                         */
                        brother.color = father.color;
                        setBlack(father);
                        setBlack(brother.rchild);
                        liftRotate(father);
                        node = root;
                        break;
                    }
                }

            } else { // node是右子节点
                brother = father.lchild; // brother是左子节点
                if (isRed(brother)) { // 情况一：brother为红色
                    /*
                    将父节点涂红，将兄弟节点涂黑，然后将当前节点的父节点作为支点右旋
                     */
                    setRed(father);
                    setBlack(brother);
                    rightRotate(father);
                }

                if (isBlack(brother)) { // 情况二、三、四：brother为黑色
                    if (isBlack(brother.lchild) && isBlack(brother.rchild)) { // 情况二：兄弟节点的两个子节点均为黑色
                        /*
                        将兄弟节点涂红，将当前节点指向其父节点，将其父节点指向当前节点的祖父节点
                         */
                        setRed(brother);
                        node = father;
                        father = getFather(node);
                    } else { // 情况三、四
                        if (isRed(brother.rchild) && isBlack(brother.lchild)) { // 情况三：兄弟节点的右子节点是红色，左子节点时黑色的
                            /*
                            把当前节点的兄弟节点涂红，把兄弟节点的右子节点涂黑，然后以兄弟节点作为支点做左旋操作
                             */
                            setRed(brother);
                            setBlack(brother.rchild);
                            liftRotate(brother);
                        }

                        // 情况四：兄弟节点的左子节点是红色，右子节点任意颜色
                        /*
                        把兄弟节点涂成父节点的颜色，再把父节点涂黑，把兄弟节点的左子节点涂黑，然后以当前节点的父节点为支点做右旋操作
                         */
                        brother.color = father.color;
                        setBlack(father);
                        setBlack(brother.lchild);
                        rightRotate(father);
                        node = root;
                        break;
                    }
                }

            }
        }

        if (node != null) {
            setBlack(node);
        }
    }

    public void find(T data) {
        RBNode<T> node = searchNode(data);
        if (node == null) {
            System.out.println("未找到");
        } else {
            System.out.println("找到了");
        }
    }

    public void preTraversal(RBNode<T> node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " ");
        if (isBlack(node)) {
            System.out.print("BLACK ");
        } else {
            System.out.print("RED ");
        }
        preTraversal(node.lchild);
        preTraversal(node.rchild);
    }

    public void inTraversal(RBNode<T> node) {
        if (node == null) {
            return;
        }
        inTraversal(node.lchild);
        System.out.print(node.data + " ");
        if (isBlack(node)) {
            System.out.print("BLACK ");
        } else {
            System.out.print("RED ");
        }
        inTraversal(node.rchild);

    }

    public void postTraversal(RBNode<T> node) {
        if (node == null) {
            return;
        }
        postTraversal(node.lchild);
        postTraversal(node.rchild);
        System.out.print(node.data + " ");
        if (isBlack(node)) {
            System.out.print("BLACK ");
        } else {
            System.out.print("RED ");
        }
    }

    public void getMin(RBNode<T> node) {
        if (node == null) {
            return;
        }
        while (node.lchild != null) {
            node = node.lchild;
        }
        System.out.println(node.data);
    }

    public void getMax(RBNode<T> node) {
        if (node == null) {
            return;
        }
        while (node.rchild != null) {
            node = node.rchild;
        }
        System.out.println(node.data);
    }

    public void showRChild(RBNode<T> node) {
        if (node.rchild != null) {
            System.out.println(node.rchild.data);
        } else {
            System.out.println("rchild is null");
        }
    }

    public void showLChild(RBNode<T> node) {
        if (node.lchild != null) {
            System.out.println(node.lchild.data);
        } else {
            System.out.println("lchild is null");
        }
    }

    public void showRoot() {
        System.out.println(this.getRoot().data);
    }
}


