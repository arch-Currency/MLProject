# MLProject

**深度学习基础算法的 C++ 实现**

## 目前已完成：

### 基础张量 (Tensor) 操作

#### 1. 构建

1. 构建 Tensor
2. default 构建
3. copy move 构造函数

#### 2. 索引 切片

1. 索引
2. 切片

#### 3. 二维张量 (矩阵) 操作

1. 

## 待完成：

### 形状操作：
- **转置（Transpose）**：交换张量的维度（特别是二维矩阵）。

### 逐元素运算：
- **逐元素加法**：对张量中的每个元素进行加法运算。
- **逐元素减法**：对张量中的每个元素进行减法运算。
- **逐元素乘法**：对张量中的每个元素进行乘法运算。
- **逐元素除法**：对张量中的每个元素进行除法运算。

### 聚合操作：
- **求和**：计算张量所有元素的和。
- **均值**：计算张量所有元素的均值。

## 逐步增加的高级张量操作

### 2.1 矩阵与高维张量运算
- **矩阵乘法（Dot product）**：用于二维或更高维度的张量。
- **批量矩阵乘法（Batch matrix multiplication）**：对一批矩阵进行乘法。

### 2.2 高级形状变换
- **广播（Broadcasting）**：处理形状不完全匹配的张量操作。
- **拼接（Concatenate）**：沿某一轴将多个张量拼接。
- **切分（Split）**：将一个张量分割为多个子张量。

### 2.3 张量的统计与分析
- **最大值（Max）**：返回张量中的最大值。
- **最小值（Min）**：返回张量中的最小值。
- **标准差（Standard deviation）**：计算张量所有元素的标准差。
- **方差（Variance）**：计算张量所有元素的方差。

### 2.4 索引与切片操作的扩展
- **高级索引**：使用布尔数组或整数数组对张量进行索引。
- **负索引**：从张量的末尾进行索引。

### 2.5 张量变换
- **展平（Flatten）**：将多维张量展平成一维张量。
- **重新排列维度（Permute）**：改变张量维度的顺序。

### 2.6 随机张量生成
- **随机生成张量**：生成指定形状和分布的张量（例如，均匀分布、高斯分布等）。

### 2.7 批量归一化与正则化
- **归一化（Normalization）**：将张量的元素调整到指定的范围。
- **标准化（Standardization）**：将张量的元素变为均值为 0，标准差为 1。

### 2.8 神经网络相关操作
- **激活函数**：如 ReLU、Sigmoid、Tanh 等，通常用于神经网络中。
- **卷积操作（Convolution）**：在图像处理和神经网络中广泛使用的操作。


