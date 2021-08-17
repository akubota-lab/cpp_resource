## cvチーム 2021 c++勉強会用リポジトリ

コンパイラはdockerコンテナ内のgccを利用する。

### 環境構築手順
- リポジトリのクローン  
```git clone git@github.com:akubota-lab/cpp_resource.git```

- docker, docker-composeのインストール
- docker コンテナ起動  
  ```cd cpp_resource```  
  ```docker compose up -d```
- コンテナ内のシェルに入る  
  ```docker exec -it cpp_study bash```
- コンパイルと実行の確認  
  ```cd src/01/hello```  
  ```g++ -o ./src/hello/hello.out ./src/hello/hello.cpp```  
  ```./src/hello/hello ```

### リンク
- [勉強会google drive](https://drive.google.com/drive/folders/1TOsHqS-WhmQut8p7lIOdJPDxP-dhP_4E)