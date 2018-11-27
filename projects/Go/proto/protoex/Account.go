// Automatically generated by the Fast Binary Encoding compiler, do not modify!
// https://github.com/chronoxor/FastBinaryEncoding
// Source: protoex.fbe
// Version: 1.1.0.0

package protoex

import "fmt"
import "strconv"
import "strings"
import "../fbe"
import "../proto"

// Workaround for Go unused imports issue
var _ = fbe.Version
var _ = proto.Version

// Workaround for Go unused imports issue
var _ = fmt.Print
var _ = strconv.FormatInt

// Account key
type AccountKey struct {
    Uid int32
}

// Convert Account flags key to string
func (k AccountKey) String() string {
    var sb strings.Builder
    return sb.String()
}

// Account struct
type Account struct {
    Uid int32 `json:"uid"`
    Name string `json:"name"`
    State StateEx `json:"state"`
    Wallet Balance `json:"wallet"`
    Asset *Balance `json:"asset"`
    Orders []Order `json:"orders"`
}

// Create a new Account struct
func NewAccount() *Account {
    return &Account{
        Uid: 0,
        Name: "",
        State: StateEx_initialized | StateEx_bad | StateEx_sad,
        Wallet: *NewBalance(),
        Asset: nil,
        Orders: make([]Order, 0),
    }
}

// Create a new Account struct from JSON
func NewAccountFromJSON(buffer []byte) (*Account, error) {
    result := *NewAccount()
    err := fbe.Json.Unmarshal(buffer, &result)
    if err != nil {
        return nil, err
    }
    return &result, nil
}

// Struct shallow copy
func (s Account) Copy() *Account {
    var result = s
    return &result
}

// Struct deep clone
func (s Account) Clone() *Account {
    var result = s
    return &result
}

// Get the struct key
func (s Account) Key() AccountKey {
    return AccountKey{
        Uid: s.Uid,
    }
}

// Convert struct to optional
func (s Account) Optional() *Account {
    return &s
}

// Convert struct to string
func (s Account) String() string {
    var sb strings.Builder
    sb.WriteString("Account(")
    sb.WriteString("uid=")
    sb.WriteString(strconv.FormatInt(int64(s.Uid), 10))
    sb.WriteString(",name=")
    sb.WriteString("\"" + s.Name + "\"")
    sb.WriteString(",state=")
    sb.WriteString(fmt.Sprintf("%v", s.State))
    sb.WriteString(",wallet=")
    sb.WriteString(fmt.Sprintf("%v", s.Wallet))
    sb.WriteString(",asset=")
    if s.Asset != nil { 
        sb.WriteString(fmt.Sprintf("%v", *s.Asset))
    } else {
        sb.WriteString("null")
    }
    sb.WriteString(",orders=")
    if s.Orders != nil {
        first := true
        sb.WriteString(",orders=[" + strconv.FormatInt(int64(len(s.Orders)), 10) + "][")
        for _, v := range s.Orders {
            if first { sb.WriteString("") } else { sb.WriteString(",") }
            sb.WriteString(fmt.Sprintf("%v", v))
            first = false
        }
        sb.WriteString("]")
    } else {
        sb.WriteString(",orders=[0][]");
    }
    sb.WriteString(")")
    return sb.String()
}

// Convert struct to JSON
func (s Account) JSON() ([]byte, error) {
    return fbe.Json.Marshal(&s)
}
