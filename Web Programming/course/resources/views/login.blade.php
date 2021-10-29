<form action="/login" method="post">
    @csrf
        <label for="fname">Nama</label><br>
        <input type="text" name="name" id="fname"><br>
        <label for="fname">Email</label><br> 
        <input type="email" name="email" id="femail"><br>
        <label for="fname">Password</label><br>
        <input type="password" name="password" id="fpassword"><br>
        <button type="submit" class="btn btn-primary">Submit</button>
    </form>