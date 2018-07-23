package com.scau;

public class RBTree<T extends Comparable<T>> {
    private RBNode<T> root;//树的根节点
    final private static boolean RED = true;
    final private static boolean BLACK = false;


    public RBTree() {
        this.root = null;
    }

    public RBNode<T> getRoot() {
        return root;
    }

    public void setRoot(RBNode<T> root) {
        this.root = root;
    }

    public void leftRotate(RBNode<T> node) {
        RBNode<T> newRootNode = node.getRchild();//左旋后新的父节点
        if (newRootNode == null) {
            return;
        }
        node.setRchild(newRootNode.getLchild());
        newRootNode.getLchild().setFather(node);
        newRootNode.setLchild(node);
        newRootNode.setFather(node.getFather());
        if (node.getFather() == null) {
            this.setRoot(newRootNode);
        } else {
            if (node == node.getFather().getLchild()) {
                node.getFather().setLchild(newRootNode);
            } else {
                node.getFather().setRchild(newRootNode);
            }
        }
        node.setFather(newRootNode);
    }

    public void rightRotate(RBNode<T> node) {
        RBNode<T> newRootNode = node.getLchild();//右旋后新的父节点
        if (newRootNode == null) {
            return;
        }
        node.setLchild(newRootNode.getRchild());
        newRootNode.getRchild().setFather(node);
        newRootNode.setRchild(node);
        newRootNode.setFather(node.getFather());
        if (node.getFather() == null) {
            this.setRoot(newRootNode);
        } else {
            if (node.getFather().getRchild() == node) {
                node.getFather().setRchild(newRootNode);
            } else {
                node.getFather().setLchild(newRootNode);
            }
        }
        node.setFather(newRootNode);
    }

//    public void colorChange(RBNode<T> node) {
//        if (node == null) {
//            return;
//        }
//        if (node.isColor() == RED) {
//            //红改黑
//            node.setColor(BLACK);
//        } else {
//            //黑改红
//            node.setColor(RED);
//        }
//    }

    public void setRed(RBNode<T> node) { // 把节点涂成红色
        node.setColor(RED);
    }

    public void setBlack(RBNode<T> node) { // 把节点涂成黑色
        node.setColor(BLACK);
    }

    public void addRBNode(T data) throws Exception {
        RBNode<T> newNode = new RBNode<>(data);//新建节点
        RBNode<T> rootCopy = root;//root的副本，便于下面操作
        RBNode<T> temp = root;//保存rootCopy父节点
        while (rootCopy != null) {
            temp = rootCopy;//保存rootCopy
            int t = newNode.getData().compareTo(rootCopy.getData());
            if (t > 0) rootCopy = rootCopy.getRchild();
            else if(t < 0) rootCopy = rootCopy.getLchild();
            else throw new Exception("红黑树没有键值相等的节点，插入失败");
        }
        if (rootCopy == null) {
            //一个节点都没有，设新节点为根节点，并涂为黑色
            this.setRoot(newNode);
            this.setBlack(newNode);
        } else {
            if (newNode.getData().compareTo(rootCopy.getData()) > 0) {
                rootCopy.setRchild(newNode);
            } else {
                rootCopy.setLchild(newNode);
            }
            newNode.setFather(rootCopy);
        }

        //插入调整调整
        this.addAdjust(newNode);

    }

    /**
     *    下面三种情况需要进行插入调整
     *
     *    ps:叔叔节点为null时为黑色
     *
     *    1、插入节点的父节点是祖父节点的左子节点
     *
     *    1-1. 插入节点的父节点和其叔叔节点（祖父节点的另一个子节点）均为红色的；
     *
     *    1-2. 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的右子节点；
     *
     *    1-3. 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的左子节点。
     *
     *    2、插入节点的父节点是祖父节点的右子节点
     *
     *    2-1. 插入节点的父节点和其叔叔节点（祖父节点的另一个子节点）均为红色的；
     *
     *    2-2. 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的左子节点；
     *
     *    2-3. 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的右子节点。
     *
     */
    public void addAdjust(RBNode<T> newNode) {

        RBNode<T> temp = newNode.getFather().getFather();
        temp = temp.getLchild() == newNode.getFather() ? temp.getRchild() : temp.getLchild();//把temp定位到newNode的叔叔节点
        if (newNode.getFather().isColor() == RED && temp != null && temp.isColor() == RED) { // case 1-1 and 2-1
//            newNode = addAdjust1(newNode);
            // 解决方案：把插入节点的父节点和叔叔节点涂成黑色、祖父节点涂成红色，把当前节点定位到其祖父节点
            setBlack(newNode.getFather());
            setBlack(temp);
            setRed(temp.getFather());
            newNode = temp.getFather();
        }

        temp = temp.getLchild() == newNode.getFather() ? temp.getRchild() : temp.getLchild();//把temp定位到newNode的叔叔节点
        if (newNode.getFather() == newNode.getFather().getFather().getLchild()) {//case 1 : 插入节点的父节点是祖父节点的左子节点
            if (newNode.getFather().isColor() == RED && (temp == null || temp.isColor() == BLACK) && newNode == newNode.getFather().getRchild()) {
                /*
                case 1-2 : 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的右子节点
                解决方案：把当前节点定位到其父节点，以新的当前节点为支点左旋
                 */
                newNode = newNode.getFather();
                leftRotate(newNode);
            }
        } else { // case 2 : 插入节点的父节点是祖父节点的右子节点
            if (newNode.getFather().isColor() == RED && (temp == null || temp.isColor() == BLACK) && newNode == newNode.getFather().getLchild()) {
                /*
                case 2-2 : 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的左子节点
                解决方案：把当前节点定位到其父节点，以新的当前节点为支点右旋
                 */
                newNode = newNode.getFather();
                rightRotate(newNode);
            }
        }

        temp = temp.getLchild() == newNode.getFather() ? temp.getRchild() : temp.getLchild();//把temp定位到newNode的叔叔节点
        if (newNode.getFather() == newNode.getFather().getFather().getLchild()) {//case 1 : 插入节点的父节点是祖父节点的左子节点
            if (newNode.getFather().isColor() == RED && (temp == null || temp.isColor() == BLACK) && newNode == newNode.getFather().getLchild()) {
                /*
                case 2-3 : 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的左子节点
                解决方案：把当前节点的父节点涂黑、祖父节点涂红，以当前节点的祖父节点为支点右旋
                 */
                setBlack(newNode.getFather());
                setRed(newNode.getFather().getFather());
                rightRotate(newNode.getFather().getFather());
            }
        } else { // case 2 : 插入节点的父节点是祖父节点的右子节点
            if (newNode.getFather().isColor() == RED && (temp == null || temp.isColor() == BLACK) && newNode == newNode.getFather().getRchild()) {
                /*
                case 1-3 : 插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的右子节点
                解决方案：把当前节点的父节点涂黑、祖父节点涂红，以当前节点的祖父节点为支点左旋
                 */
                setBlack(newNode.getFather());
                setRed(newNode.getFather().getFather());
                leftRotate(newNode.getFather().getFather());
            }

        }
//        temp = newNode.getFather().getFather();//当前节点的祖父节点
//        temp = temp.getLchild() == newNode.getFather() ? temp.getRchild() : temp.getLchild();//把temp定位到newNode的叔叔节点
//        if (newNode.getFather().isColor() == RED && (temp == null || temp.isColor() == BLACK) && newNode == newNode.getFather().getRchild()) {
////            newNode = addAdjust2(newNode);
//        }
//        temp = newNode.getFather().getFather();//当前节点的祖父节点
//        temp = temp.getLchild() == newNode.getFather() ? temp.getRchild() : temp.getLchild();//把temp定位到newNode的叔叔节点
//        if (newNode.getFather().isColor() == RED && (temp == null || temp.isColor() == BLACK) && newNode == newNode.getFather().getLchild()) {
////            addAdjust3(newNode);
//        }


    }

//    public RBNode<T> addAdjust1(RBNode<T> newNode) {
//        /**
//         * 情况描述：插入节点的父节点和其叔叔节点（祖父节点的另一个子节点）均为红色
//         * 解决方案：将当前节点的父节点和叔叔节点涂黑，将祖父节点(7)涂红，再将当前节点指向其祖父节点并返回，
//         *          把情况1转换为情况2
//         */
//        newNode = newNode.getFather().getFather();
//        this.colorChange(newNode.getLchild());//红变黑
//        this.colorChange(newNode.getRchild());//红变黑
//        this.colorChange(newNode);//黑变红
//        return newNode;
//    }
//
//    public RBNode<T> addAdjust2(RBNode<T> newNode) {
//        /**
//         * 情况描述：插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的右子节点
//         * 解决方案：将当前节点的父节点作为新的节点，以新的当前节点为支点做左旋操作，并返回新的当前节点
//         *          把情况2转换为情况3
//         */
//        newNode = newNode.getFather();
//        leftRotate(newNode);
//        return newNode;
//    }
//
//    public void addAdjust3(RBNode<T> newNode) {
//        /**
//         * 情况描述：插入节点的父节点是红色，叔叔节点是黑色，且插入节点是其父节点的左子节点。
//         * 解决方案：将当前节点的父节点涂黑，将祖父节点涂红，在祖父节点为支点做右旋操作
//         */
//        newNode = newNode.getFather();
//        this.colorChange(newNode);
//        newNode = newNode.getFather();
//        this.colorChange(newNode);
//        rightRotate(newNode);
//    }

    public RBNode<T> find(T data) {
        RBNode<T> node = root;
        while (node != null) {
            if (node.getData().compareTo(data) > 0) {
                node = node.getLchild();
            } else if (node.getData().compareTo(data) < 0) {
                node = node.getRchild();
            } else {
                return node;
            }
        }
        return null;
    }

    public boolean removeNode(T data) {
        RBNode<T> node = find(data);
        if (node == null) {
            return false;
        }

        if (node.getLchild() == null && node.getRchild() == null) {
            //删除节点为叶子，直接删除
            if (node.getFather().getLchild() == node) {
                node.getFather().setLchild(null);
            } else {
                node.getFather().setRchild(null);
            }
        } else if (node.getLchild() == null && node.getRchild() != null || node.getLchild() != null && node.getRchild() == null) {
            //删除节点只有一个孩子，把其父节点和其子节点相连
            RBNode<T> father = node.getFather();
            RBNode<T> child = node.getLchild() == null ? node.getRchild() : node.getLchild();
            if (father.getLchild() == node) {
                father.setLchild(child);
            } else {
                father.setRchild(child);
            }
            child.setFather(father);
        } else {
            //删除节点有两个孩子
            RBNode<T> replace = node.getLchild();
            RBNode<T> pre = replace;
            while (replace != null) {
                //查找node的直接前驱
                pre = replace;
                replace = replace.getRchild();
            }
            //something to do
        }
        return true;
    }
}

