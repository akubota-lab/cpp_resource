## cvチーム 2021 c++勉強会用リポジトリ

コンパイラはdockerコンテナ内のgccを利用する。

### 環境構築手順
- リポジトリのクローン  
```git clone git@github.com:akubota-lab/cpp_study.git```

- docker, docker-composeのインストール[こちら](https://docs.docker.jp/compose/install.html#pip)
- docker コンテナ起動  
  ```cd cpp_resource```  
  ```docker compose up -d```
- コンテナ内のシェルに入る  
  ```docker exec -it cpp_study bash```
- コンパイルと実行の確認  
  ```cd src/01/hello```  
  ```g++ -o hello.out hello.cpp```  
  ```./hello.out ```

### リンク
- [勉強会google drive](https://drive.google.com/drive/folders/1TOsHqS-WhmQut8p7lIOdJPDxP-dhP_4E)
